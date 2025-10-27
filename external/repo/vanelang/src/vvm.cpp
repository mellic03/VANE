#include <vanevm/vvm.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

template <typename OutType, typename InType>
OutType vvmcast( const InType &in )
{
    union UType { InType i; OutType o; };
    return (UType{in}).o;
}

constexpr uint32_t vvmalignd( uint32_t x, uint32_t a )
{ return x & ~(a-1); }

constexpr uint32_t vvmalignu( uint32_t x, uint32_t a )
{ return (x + a-1) & ~(a-1); }

void vanevm::VmCtx::execute()
{
    char msgstr[12] = "Michael\n\0\0\0";
    auto *msgbuf = (uint32_t*)msgstr;

    uint32_t prg[] = {
        // OP_PUSH, (uint32_t)50,
        // OP_PUSH, (uint32_t)21,
        // OP_MUL,
        // OP_POPX,
        // OP_OUTX,
        OP_STX,  (uint32_t)512,  // mov AX, 512
        OP_WTX,  msgbuf[0],      // mem[AX++] = Mich
        OP_WTX,  msgbuf[1],      // mem[AX++] = ael\0
        OP_WTX,  msgbuf[2],      // mem[AX++] = ael\0
        OP_OUTS, (uint32_t)512,
        OP_EXIT
    };

    uint32_t *mem = new uint32_t[1024];
    std::memset(mem, 0, 1024*sizeof(uint32_t));
    std::memcpy(mem, prg, sizeof(prg));

    void *jtab[] = {
        #define X(Nm) &&jtab_##Nm,
        VVM_OPNAMES
        #undef X
    };
    #define DISPATCH() goto *jtab[mem[IP++]];
    #define FETCH()  mem[IP++]

    #define BINARY_OP(Op) \
    { \
        auto UY = vstk[--SP]; \
        auto UX = vstk[--SP]; \
        vstk[SP++] = UX Op UY; \
    }

    #define BINARY_FOP(Op) \
    { \
        float FY = vvmcast<float>(vstk[--SP]); \
        float FX = vvmcast<float>(vstk[--SP]); \
        vstk[SP++] = vvmcast<uint32_t>(FX Op FY); \
    }


    IP=0, SP=0;
    AC=0, AX=0, AY=0;

    DISPATCH();


jtab_NONE: printf("Invalid opcode (%u)\n", mem[IP-1]); goto jtab_EXIT;
jtab_NOP:                 DISPATCH();
jtab_ADD:  BINARY_OP(+);  DISPATCH();
jtab_SUB:  BINARY_OP(-);  DISPATCH();
jtab_MUL:  BINARY_OP(*);  DISPATCH();
jtab_DIV:  BINARY_OP(/);  DISPATCH();
jtab_FADD: BINARY_FOP(+); DISPATCH();
jtab_FSUB: BINARY_FOP(-); DISPATCH();
jtab_FMUL: BINARY_FOP(*); DISPATCH();
jtab_FDIV: BINARY_FOP(/); DISPATCH();

#define OPDEF_NAXY(Nm) \
    jtab_##Nm:    {FnDef(mem[IP++])} DISPATCH();\
    jtab_##Nm##A: {FnDef(AC)} DISPATCH();\
    jtab_##Nm##X: {FnDef(AX)} DISPATCH();\
    jtab_##Nm##Y: {FnDef(AY)} DISPATCH();

#define OPDEF_AXY(Nm) \
    jtab_##Nm##A: {FnDef(AC)} DISPATCH();\
    jtab_##Nm##X: {FnDef(AX)} DISPATCH();\
    jtab_##Nm##Y: {FnDef(AY)} DISPATCH();

// PUSH
#define FnDef(Rg) vstk[SP++] = Rg;
OPDEF_NAXY(PUSH);
#undef FnDef

// POP
#define FnDef(Rg) Rg = vstk[SP++];
OPDEF_NAXY(POP);
#undef FnDef

// ST{A,X,Y}
#define FnDef(Rg) Rg = FETCH();
OPDEF_AXY(ST);
#undef FnDef

// WT{A,X,Y}
#define FnDef(Rg) mem[Rg++] = FETCH();
OPDEF_AXY(WT);
#undef FnDef

// OUT{A,X,Y}
#define FnDef(Rg) printf("%u", Rg);
OPDEF_AXY(OUT);
#undef FnDef

jtab_OUTC: { // print four chars starting at mem[dword]
    auto *base = (const char*)(mem + FETCH());
    for (int i=0; i<4; i++)
        printf("%c", base[i]);
}   DISPATCH();

jtab_OUTU: { // print dword
    printf("%u", FETCH());
}   DISPATCH();

jtab_OUTS: { // print string starting at mem[dword]
    printf("%s", (const char*)(mem + FETCH()));
}   DISPATCH();


jtab_JMP: {
    IP = mem[IP];
}   DISPATCH();

jtab_CALL: {
    cstk.push({IP+1, SP});
    IP = mem[IP];
    SP = vvmalignu(SP, 2);
}   DISPATCH();

jtab_RET: {
    auto [ip, sp] = cstk.pop();
    IP = ip;
    SP = sp;
}   DISPATCH();

jtab_EXIT:
    return;

}


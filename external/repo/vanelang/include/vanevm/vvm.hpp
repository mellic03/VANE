#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <stack>


namespace vanevm
{
    #define VVM_OPNAMES \
        X(NONE) \
        X(NOP) \
        \
        X(ADD) \
        X(SUB) \
        X(MUL) \
        X(DIV) \
        X(FADD) \
        X(FSUB) \
        X(FMUL) \
        X(FDIV) \
        \
        X(PUSH) \
        X(PUSHA) \
        X(PUSHX) \
        X(PUSHY) \
        \
        X(POP) \
        X(POPA) \
        X(POPX) \
        X(POPY) \
        \
        X(STA) \
        X(STX) \
        X(STY) \
        \
        X(WTA) \
        X(WTX) \
        X(WTY) \
        \
        X(OUTA) \
        X(OUTX) \
        X(OUTY) \
        \
        X(OUTC) \
        X(OUTU) \
        X(OUTS) \
        \
        X(JMP) \
        X(CALL) \
        X(RET) \
        X(EXIT)

    enum OP_: uint32_t
    {
        #define X(Nm) OP_##Nm,
        VVM_OPNAMES
        #undef X
    };

    class VmCtx;
}


class vanevm::VmCtx
{
public:
    VmCtx() {  }
    void execute();

private:
    template <typename T>
    struct VmStack: public std::stack<T>
    {
        T pop()
        {
            assert((!std::stack<T>::empty()));
            T x=std::stack<T>::top(); pop();
            return x;
        }
    };

    struct StackFrame
    {
        uint32_t ip;
        uint32_t sp;
        // uint32_t *prev;
    };

    uint32_t  IP;
    uint32_t  SP;
    uint32_t  AC, AX, AY, AZ, AW;
    uint32_t  BX, BY;
    uint32_t *vstk = new uint32_t[1024];
    VmStack<StackFrame> cstk; // call stack
    
};
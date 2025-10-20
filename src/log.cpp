#include <vane/log.hpp>
#include <cassert>
#include <cstdarg>
#include <cstdio>

/*
#ifdef MEMU_LOGGING
    #define LAZY_AF(Tit, Msg) \
    { \
        printf("[%s] ", (Tit)); \
        \
        va_list vlist; \
        __builtin_va_start(vlist, Msg); \
        vprintf(Msg, vlist); \
        __builtin_va_end(vlist); \
    }
    // va_start(vlist, msg);
    // vprintf(msg, vlist);
    // va_end(vlist);

#else
    #define LAZY_AF(Tit, Msg)

#endif


void memu::log::Info( const char *msg, ... )
{
    LAZY_AF("Info", msg);
}

void memu::log::Warn( const char *msg, ... )
{
    LAZY_AF("Warn", msg);
}
// void memu::log::Asrt( bool cond, const char *msg, ... )
// {
//     // LAZY_AF(cond ? "Asrt PASS" : "Asrt FAIL", msg);

//     if (!cond)
//     {
//         LAZY_AF("Asrt FAIL", msg);
//         assert(cond);
//     }
// }

#undef LAZY_AF
*/


static FILE *dstfile = stdout;
static int indent = 0;


syslog::syslog( const char *fmt, ... )
{
    syslog::_putIndent();
    syslog::_print("[");

    va_list vlist;
    va_start(vlist, fmt);
    syslog::_print(fmt, vlist);
    va_end(vlist);

    syslog::_print("]\n");
    syslog::_putIndent();
    syslog::_print("{\n");
    _pushIndent();
}


syslog::~syslog()
{
    _popIndent();
    syslog::_putIndent();
    syslog::_print("}\n");
}


void
syslog::operator()( const char *fmt, ... )
{
    for (int i=0; i<indent; i++)
        printf(" ");

    va_list vlist;
    va_start(vlist, fmt);
    vprintf(fmt, vlist);
    va_end(vlist);

    printf("\n");
}


void
syslog::vprint( const char *fmt, va_list vlist )
{
    vprintf(fmt, vlist);
}


void
syslog::print( const char *fmt, ... )
{
    va_list vlist;
    va_start(vlist, fmt);
    this->vprint(fmt, vlist);
    va_end(vlist);
}



void syslog::setDstFile( FILE *fh )
{
    dstfile = fh;
}

void syslog::_pushIndent( int n )
{
    indent += n;
}

void syslog::_popIndent ( int n )
{
    indent -= n;
}

void syslog::_putIndent()
{
    for (int i=0; i<indent; i++)
        printf(" ");
}

void syslog::_print( const char *fmt, ... )
{
    va_list vlist;
    va_start(vlist, fmt);
    vprintf(fmt, vlist);
    va_end(vlist);
}

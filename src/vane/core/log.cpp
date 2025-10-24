#include <vane/core/log.hpp>


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

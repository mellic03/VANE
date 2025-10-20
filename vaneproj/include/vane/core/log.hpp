#pragma once

#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <iostream>


class syslog
{
public:
    syslog( const char *fmt, ... );
    ~syslog();
    void operator()( const char *fmt, ... );
    void vprint( const char *fmt, va_list vlist );
    void print( const char *fmt, ... );

    static void setDstFile( FILE* );

private:
    static void _pushIndent( int n=4 );
    static void _popIndent( int n=4 );
    static void _putIndent();
    static void _print( const char *fmt, ... );
};



#define VANE_DEBUG

#ifdef VANE_DEBUG
    #define VANE_ASSERT(Cndtn, Mesge) \
    do { \
        if (! (Cndtn)) { \
            std::cerr << "Assertion `" #Cndtn "` failed in " << __FILE__ \
                        << " line " << __LINE__ << ": " << Mesge << std::endl; \
            std::terminate(); \
        } \
    } while (false)

#else
    #define VANE_ASSERT(Cndtn, Mesge) do { } while (false)

#endif


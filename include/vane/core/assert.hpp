#pragma once

#include <cassert>
#include <cstdio>
#include <iostream>


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


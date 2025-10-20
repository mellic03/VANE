#pragma once

#include "types.hpp"
#include <set>
#include <string>


namespace vane
{
    class Platform;
}


class vane::Platform
{
public:
    Platform();
    NativeWindow *createWindow( const std::string &title, int w, int h );
    void destroyWindow( NativeWindow* );

private:
    std::set<NativeWindow*> mWindows;

};



class vane::NativeWindow
{
public:
    friend class vane::Platform;

private:
    void *mWinSDL;
    void *mCtxGL;
    NativeWindow( const std::string &title, int w, int h );
    // NativeWindow( const char *title, int w, int h, int s=1, size_t r=1 );

};

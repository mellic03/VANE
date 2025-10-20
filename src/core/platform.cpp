#include <vane/core/platform.hpp>
#include <vane/core/log.hpp>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace vane;



Platform::Platform()
{
    syslog log("Platform::Platform");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        log("Error: \"%s\"", SDL_GetError());
        exit(1);
    }

    if (glewInit() != GLEW_OK)
    {
        log("Error initializing glew");
        exit(1);
    }
}


NativeWindow *Platform::createWindow( const std::string &title, int w, int h )
{
    auto *win = new NativeWindow(title, w, h);
    mWindows.insert(win);


    return win;
}


void Platform::destroyWindow( NativeWindow* )
{

}


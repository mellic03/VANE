#include <vane/platform/platform.hpp>
#include <vane/core/log.hpp>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace vane;


Platform::Platform( vane::Engine &engine )
:   EngineRef(engine),
    mMainWin(nullptr)
{
    syslog log("Platform::Platform");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        log("Error: \"%s\"", SDL_GetError());
        exit(1);
    }

    mMainWin = createWindow("VANE", 512, 512);
    if (glewInit() != GLEW_OK)
    {
        log("Error initializing glew");
        exit(1);
    }
}


void Platform::update()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                KeyboardIO::update(e);
                break;

            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEWHEEL:
                MouseIO::update(e);
                break;
        }
    }
}


NativeWindow *Platform::mainWindow()
{
    return mMainWin;
}


NativeWindow *Platform::createWindow( const std::string &title, int w, int h )
{
    auto *win = new NativeWindow(title, w, h);
    mWindows.insert(win);
    return win;
}


void Platform::destroyWindow( NativeWindow *win )
{
    VANE_ASSERT(mWindows.contains(win), "No such window!");
    VANE_ASSERT(win == mMainWin, "Cannot destroy main window!");
    mWindows.erase(win);
    delete win;
}

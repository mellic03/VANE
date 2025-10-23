#include <vane/platform/platform.hpp>
#include <vane/core/assert.hpp>
#include <vane/core/log.hpp>
#include <vane/gfx/gl.hpp>

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

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    mMainWin = createWindow("VANE", 512, 512);
    if (glewInit() != GLEW_OK)
    {
        log("Error initializing glew");
        exit(1);
    }

    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    log("Device supports OpenGL %d.%d", major, minor);
    if (!(major>=4 && minor>=5))
        log("OpenGL 4.5 required");
    VANE_ASSERT(major>=4 && minor>=5, "OpenGL 4.5 required");
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
    auto *win = new NativeWindow(*this, title, w, h);
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

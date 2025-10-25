#include "./platform.hpp"

using namespace vane;


Platform::Platform()
:   mMainWin(nullptr)
{
    syslog log("Platform::Platform");
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO))
    {
        log("Error on SDL_Init: \"%s\"", SDL_GetError());
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    mMainWin = createWindow("VANE", 512, 512);

    if (!gladLoadGL())
    {
        log("gladLoadGL error");
        exit(1);
    }

    // glewExperimental = GL_TRUE;
    // GLenum glewError = glewInit();
    // if (glewError != GLEW_OK)
    // {
    //     log("glewInit: error %u, %s", glewError, glewGetErrorString(glewError));
    //     exit(1);
    // }

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
            case SDL_EVENT_KEY_DOWN:
            case SDL_EVENT_KEY_UP:
                KeyboardIO::update(e);
                break;

            case SDL_EVENT_MOUSE_MOTION:
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            case SDL_EVENT_MOUSE_BUTTON_UP:
            case SDL_EVENT_MOUSE_WHEEL:
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

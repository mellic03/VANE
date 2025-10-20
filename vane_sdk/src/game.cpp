#include "./game.hpp"
#include <vane/log.hpp>

void MyGame::update()
{
    auto &plat = mEngine.getPlatform();
    vane::ivec2 p = plat.mousePos();
    float r = float(p.x) / 512.0f;
    float g = float(p.y) / 512.0f;
    glClearColor(r, g, 0.0f, 1.0f);

    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (plat.keyPressed(SDL_SCANCODE_ESCAPE))
    {
        mEngine.shutdown();
    }

    SDL_GL_SwapWindow(plat.mainWindow()->mWinSDL);
}


int MyGame::startup( int argc, char **argv )
{
    syslog log("MyGame::startup");

    log("argc:     %d", argc);
    for (int i=0; i<argc; i++)
        log("argv[%d]: %s", argv[i]);

    auto &engine = mEngine;
    auto &game = engine.getGame<MyGame>();

    auto *menu = game.createScene("main_menu");
          menu->createObject();

    return 0;
}


int MyGame::shutdown()
{
    // Flush logs etc
    return 0;
}

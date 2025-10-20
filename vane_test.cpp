#include <vane/vane.hpp>
#include <vane/vec.hpp>
#include <vane/core/log.hpp>

#include <SDL2/SDL.h>
#include <GL/glew.h>



class MyGame: public vane::Game
{
public:
    MyGame( vane::Engine &engine )
    :   Game(engine) {  };

    virtual void update() final {  }
};


int main( int argc, char **argv )
{
    auto &engine = *vane::Engine::createEngine<MyGame>();
    auto &plat = engine.getPlatform();
    auto &game = engine.getGame<MyGame>();

    auto *menu = game.createScene("main_menu");
    menu->createObject();

    while (true)
    {
        glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        engine.update();
        if (plat.keyPressed(SDL_SCANCODE_ESCAPE))
        {
            break;
        }

        SDL_GL_SwapWindow(plat.mainWindow()->mWinSDL);
    }

    return 0;
}
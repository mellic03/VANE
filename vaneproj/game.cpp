#include "./game.hpp"
#include <vane/core/log.hpp>
#include <vane/core/cfgparser.hpp>
#include <vane/gfx/shader.hpp>

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



// #include <json/json.hpp>
// #include <fstream>
// using json = nlohmann::json;

// static void json_test()
// {
//     std::ifstream f("gamedata/types.json");
//     json data = json::parse(f);

//     for (auto &[key, val]: data.items())
//     {
//         if (!val.is_null())
//         {
//             parse_type(key, val);
//         }
//     }
// }

int MyGame::startup( int argc, char **argv )
{
    syslog log("MyGame::startup");

    log("argc:     %d", argc);
    for (int i=0; i<argc; i++)
        log("argv[%d]: \"%s\"", i, argv[i]);

    auto &engine = mEngine;
    auto &game = engine.getGame<MyGame>();

    auto *menu = game.createScene("main_menu");
    auto *obj = menu->createObject();
          obj->giveAttr<vane::ObjAttrTransform>(vane::vec3(5.0f, 0.0f, 0.0f));

    return 0;
}


int MyGame::shutdown()
{
    // Flush logs etc
    return 0;
}

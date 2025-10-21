#include "./game.hpp"
#include <vane/core/log.hpp>
#include <vane/core/cfgparser.hpp>
#include <vane/gfx/shader.hpp>
#include <vane/vfs/vfs.hpp>

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
        log("argv[%d]: \"%s\"", i, argv[i]);

    auto &engine = mEngine;
    auto &game = engine.getGame<MyGame>();

    auto *menu = game.createScene("main_menu");
    auto *obj = menu->createObject();
          obj->giveAttr<vane::ObjAttrTransform>(vane::vec3(5.0f, 0.0f, 0.0f));

    // vane::gfx::ShaderArchive A;
    // // A.openArchive("spirv_archive.bin");
    // A.compileSPIRV("vane/shader/quad.vert", "quad.vert.spv");
    // A.compileSPIRV("vane/shader/quad.frag", "quad.frag.spv");
    // A.addFile("quad.vert.spv");
    // A.addFile("quad.frag.spv");
    // std::system("rm quad.vert.spv");
    // std::system("rm quad.frag.spv");
    // A.saveArchive("spirv_archive.bin");

    // using namespace vane;
    // vfs::FileSystem fs(512);

    // const char txt[] = "No logs here...";

    // auto *file = fs.open("/home/log.txt");
    // file->wtpos = 0;
    // fs.write(file, txt, sizeof(txt));

    // char buf[256];
    // memset(buf, 0, 256);

    // file->rdpos = 0;
    // fs.read(file, buf, sizeof(txt));

    // log("vfs: \"%s\"", buf);

    return 0;
}


int MyGame::shutdown()
{
    // Flush logs etc
    return 0;
}

#include <vane/vane.hpp>
#include <vane/core/platform.hpp>
#include <vane/core/log.hpp>


int main( int , char ** )
{
    vane::Platform plat;
    vane::Game game;

    auto *win = plat.createWindow("Test", 512, 512);

    if (!win)
    {
        return 1;
    }

    auto *menu = game.createScene("main_menu");
    menu->createObject();

    syslog A("A");
    A("CEE %d", 1);

    {
        syslog B("B");
        B("PLUS %d", 2);

        {
            syslog C("C");
            C("PLUS %d", 3);
        }
    }

    return 0;
}
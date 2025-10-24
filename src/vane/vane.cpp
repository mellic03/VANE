#include <vane/vane.hpp>
#include <vane/platform/platform.hpp>
#include <vane/core/engine.hpp>
// #include <vane/config.hpp>

using namespace vane;


int VaneApp::va_entry( int argc, char **argv, VaneApp *V )
{
    using namespace vane;

    int res = V->startup(argc, argv);
    if (res != 0) return res;

    while (V->running())
    {
        V->update();
    }

    return V->shutdown();
}


void VaneApp::update()
{
    mTicksPrev = mTicksCurr;
    mTicksCurr = SDL_GetTicks64();

    mPlatform->update();
}





// vane::CfgParser &vane::GetConfig()
// {
//     static CfgParser conf("vane.cfg");
//     return conf;
// }


// Engine::Engine()
// :   mTicksCurr(0),
//     mTicksPrev(0),
//     mPlatform(*this),
//     mGame(nullptr),
//     mRunning(true)
// {

// }


// void Engine::update()
// {
//     mTicksPrev = mTicksCurr;
//     mTicksCurr = SDL_GetTicks64();

//     mPlatform.update();
//     mGame->update();
// }

// void Engine::shutdown()
// {
//     mRunning = false;
// }

// bool Engine::running()
// {
//     return mRunning;
// }

// double Engine::tsec()
// {
//     return double(mTicksCurr) / 1000.0;
// }

// uint64 Engine::tmsec()
// {
//     return mTicksCurr;
// }

// Platform &Engine::getPlatform()
// {
//     return mPlatform;
// }

// Game *Engine::getGame()
// {
//     return mGame;
// }


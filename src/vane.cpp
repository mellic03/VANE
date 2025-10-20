#include <vane/vane.hpp>
#include <SDL2/SDL.h>

using namespace vane;


Engine::Engine()
:   mTicksCurr(0),
    mTicksPrev(0),
    mPlatform(*this),
    mGame(nullptr),
    mRunning(true)
{

}


void Engine::update()
{
    mTicksPrev = mTicksCurr;
    mTicksCurr = SDL_GetTicks64();

    mPlatform.update();
    mGame->update();
}

void Engine::shutdown()
{
    mRunning = false;
}

bool Engine::running()
{
    return mRunning;
}

double Engine::tsec()
{
    return double(mTicksCurr) / 1000.0;
}

uint64 Engine::tmsec()
{
    return mTicksCurr;
}

Platform &Engine::getPlatform()
{
    return mPlatform;
}

Game *Engine::getGame()
{
    return mGame;
}


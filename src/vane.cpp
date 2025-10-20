#include <vane/vane.hpp>
#include <SDL2/SDL.h>

using namespace vane;


void Engine::update()
{
    mTicksPrev = mTicksCurr;
    mTicksCurr = SDL_GetTicks64();

    mPlatform.update();
    mGame->update();
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


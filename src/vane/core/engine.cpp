#include <vane/core/engine.hpp>
#include <vane/core/app.hpp>
#include <vane/platform/platform.hpp>
#include <vane/platform/SDL.hpp>

using namespace vane;


Engine::Engine( vane::Platform *p, vane::VaneApp *a )
:   mPlatform(p), mVaneApp(a), mRunning(true), mTicksCurr(0), mTicksPrev(0)
{

}


void Engine::update()
{
    mTicksPrev = mTicksCurr;
    mTicksCurr = SDL_GetTicks64();

    mPlatform->update();
    mVaneApp->update();
}


#include <vane/gfx/gfx.hpp>
#include <vane/core/app.hpp>
#include <vane/core/gl.hpp>
#include <vane/core/platform.hpp>
#include <vane/vec.hpp>


void vane::GfxService::update()
{
    if (mPlat.keyPressed(SDL_SCANCODE_ESCAPE))
    {
        vane::AppExit(mApp, 0);
    }
}


void vane::GfxService::preUpdate()
{

}


void vane::GfxService::postUpdate()
{
    vec2 p = mPlat.mousePos();
    gl::ClearColor(p.x/512.0f, p.y/512.0f, 0.0f, 1.0f);
    gl::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(mPlat.mainWindow()->mWinSDL);
}



#include <vane/gfx/gfx.hpp>
#include <vane/core/gl.hpp>
#include <vane/core/platform.hpp>
#include <vane/vec.hpp>


void vane::GfxService::update()
{

}


void vane::GfxService::preUpdate()
{

}


void vane::GfxService::postUpdate()
{
    ivec2 p = mPlat.mousePos();
    gl::ClearColor(float(p.x)/512.0f, float(p.y)/512.0f, 0.0f, 1.0f);
    gl::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(mPlat.mainWindow()->mWinSDL);
}



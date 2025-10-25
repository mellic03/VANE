#pragma once

#include <vane/vane.hpp>
#include <vane/core/app.hpp>
#include <vane/core/gl.hpp>
#include <vane/core/platform.hpp>
#include <vane/core/service.hpp>
#include <vane/vec.hpp>


class GfxService: public vane::VaneService
{
public:
    using VaneService::VaneService;

    virtual void update() override {  }
    virtual void preUpdate() override {  }
    virtual void postUpdate() override
    {
        vane::ivec2 p = mPlat.mousePos();
        gl::ClearColor(float(p.x)/512.0f, float(p.y)/512.0f, 0.0f, 1.0f);
        gl::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_GL_SwapWindow(mPlat.mainWindow()->mWinSDL);
    }
};


class GameService: public vane::VaneService
{
public:
    using VaneService::VaneService;

    virtual void update() final
    {
        if (mPlat.keyPressed(SDL_SCANCODE_ESCAPE))
        {
            vane::AppExit(mApp, 0);
        }
    }
};


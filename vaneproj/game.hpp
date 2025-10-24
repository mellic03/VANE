#pragma once

#include <vane/vane.hpp>
#include <vane/world/world.hpp>


class MyVaneApp: public vane::VaneApp
{
public:
    using VaneApp::VaneApp;

    vane::GameWorld mWorld;

    virtual void update() final;
    virtual int startup(int, char**) final;
    virtual int shutdown() final;
};

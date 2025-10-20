#pragma once

#include <vane/vane.hpp>


class MyGame: public vane::Game
{
public:
    MyGame(vane::Engine &e): Game(e) {  };
    virtual void update() final;
    virtual int startup(int, char**) final;
    virtual int shutdown() final;
};

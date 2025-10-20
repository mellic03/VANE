#pragma once

#include "types.hpp"
#include <vane/core/scene.hpp>


class vane::Game: public vane::EngineRef, public vane::GameSceneGroup
{
public:
    Game( vane::Engine &e ): EngineRef(e) {  };
    virtual ~Game() = default;
    virtual void update() = 0;

protected:

};


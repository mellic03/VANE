#pragma once

#include "types.hpp"
#include "scenegroup.hpp"


class vane::Game
:   public vane::EngineRef,
    public vane::SceneGroup
{
public:
    Game( vane::Engine &e ): EngineRef(e) {  };
    virtual ~Game() = default;

    virtual void update() = 0;
    virtual int startup(int, char**) = 0;
    virtual int shutdown() = 0;
};

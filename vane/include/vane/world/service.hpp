#pragma once

#include <vane/util/reliant.hpp>

namespace vane
{
    class GameWorld;
    class GameService;
    class GameObject;
}


class vane::GameService: public util::Reliant<GameWorld>
{
public:
    GameService( GameWorld &W ): Reliant(W) {  };
    virtual ~GameService() = default;
    virtual void update() = 0;
    
protected:

};


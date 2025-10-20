#pragma once

#include <vane/types.hpp>
#include "core/game.hpp"
#include "core/object.hpp"
#include "core/scene.hpp"
#include "platform/platform.hpp"

namespace vane
{
    class Engine;

    class Game;
    class GameScene;
    class GameObject;
}


class vane::Engine
{
public:
    template <typename game_type>
    static Engine *createEngine();

    Engine( const Engine& ) = delete;
    Engine( Engine&& ) = delete;
    Engine &operator=( Engine&& ) = delete;
    Engine &operator=( const Engine& ) = delete;

    void update();
    double tsec();
    uint64 tmsec();
    Platform &getPlatform();
    Game *getGame();

    template <typename game_type>
    game_type &getGame() { return *static_cast<game_type*>(getGame()); };

private:
    uint64_t mTicksCurr;
    uint64_t mTicksPrev;
    Platform mPlatform;
    Game    *mGame;
    Engine(): mTicksCurr(0), mTicksPrev(0), mPlatform(*this), mGame(nullptr) {  };

};


template <typename game_type>
vane::Engine *vane::Engine::createEngine()
{
    auto *e = new Engine();
    e->mGame = new game_type(*e);
    return e;
}




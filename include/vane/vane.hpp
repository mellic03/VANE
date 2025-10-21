#pragma once

#include "types.hpp"
#include "core/cfgparser.hpp"
#include "core/game.hpp"
#include "core/object.hpp"
#include "core/scene.hpp"
#include "gfx/gfx.hpp"
#include "platform/platform.hpp"


namespace vane
{
    class Engine;
    class Game;
    class GameScene;
    class GameObject;

    namespace detail
    {
        struct EngFren;
    }

    template <typename game_type>
    int vmain( int argc, char **argv );
}


class vane::Engine
{
public:
    Engine( const Engine& ) = delete;
    Engine( Engine&& ) = delete;
    Engine &operator=( Engine&& ) = delete;
    Engine &operator=( const Engine& ) = delete;

    void update();
    void shutdown();
    bool running();

    double tsec();
    uint64 tmsec();
    Platform &getPlatform();
    Game *getGame();

    template <typename game_type>
    game_type &getGame() { return *static_cast<game_type*>(getGame()); }

private:
    friend class detail::EngFren;

    uint64_t mTicksCurr;
    uint64_t mTicksPrev;
    Platform mPlatform;
    Game    *mGame;
    bool     mRunning;
    Engine();
    ~Engine() {  }

};






namespace vane
{
    using vmain_t = int (*)(int, char**, Engine&);

    template <typename game_type>
    int StartVane( int argc, char **argv );
}


struct vane::detail::EngFren
{
    template <typename game_type>
    static Engine *create()
    {
        auto *e = new Engine();
        e->mGame = new game_type(*e);
        return e;
    }

    static void destroy( Engine *e )
    {
        delete e;
    }
};


template <typename game_type>
int vane::vmain( int argc, char **argv )
{
    using namespace vane;

    auto *engine = detail::EngFren::create<game_type>();
    auto *game   = engine->getGame();

    int res = game->startup(argc, argv);
    if (res != 0) return res;

    while (engine->running())
    {
        engine->update();
    }

    res = game->shutdown();
    return res;
}
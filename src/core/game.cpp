#include <vane/core/game.hpp>
#include <vane/core/scene.hpp>
#include <vane/core/object.hpp>

using namespace vane;


GameScene *Game::createScene( const std::string &label )
{
    auto *obj = new GameScene(label);
    mScenes.insert(obj);
    return obj;
}


void Game::destroyScene( GameScene *S )
{
    if (mScenes.contains(S))
    {
        mScenes.erase(S);
    }
}

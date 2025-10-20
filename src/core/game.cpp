#include <vane/core/game.hpp>
#include <vane/core/log.hpp>
#include <vane/core/scene.hpp>
#include <vane/core/object.hpp>

using namespace vane;


GameScene *Game::createScene( const std::string &label )
{
    mScenes[label] = new GameScene(label);
    return mScenes[label];
}


GameScene *Game::getScene( const std::string &label )
{
    if (mScenes.contains(label))
        return mScenes[label];
    return nullptr;
}


void Game::destroyScene( const std::string &label )
{
    VANE_ASSERT(mScenes.contains(label), "Null scene!");
}


void Game::destroyScene( GameScene *scene )
{
    VANE_ASSERT(scene != nullptr, "Null scene!");
    std::string label = scene->mLabel;
    if (mScenes.contains(label))
    {
        delete mScenes[label];
        mScenes.erase(label);
    }
}

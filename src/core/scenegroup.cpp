#include <vane/core/scene.hpp>
#include <vane/core/assert.hpp>

using namespace vane;


GameScene *SceneGroup::createScene( const std::string &label )
{
    mScenes[label] = new GameScene(label);
    return mScenes[label];
}

GameScene *SceneGroup::getScene( const std::string &label )
{
    if (mScenes.contains(label))
        return mScenes[label];
    return nullptr;
}

void SceneGroup::destroyScene( const std::string &label )
{
    VANE_ASSERT(mScenes.contains(label), "Null scene!");
}

void SceneGroup::destroyScene( GameScene *scene )
{
    VANE_ASSERT(scene != nullptr, "Null scene!");
    std::string label = scene->mLabel;
    if (mScenes.contains(label))
    {
        delete mScenes[label];
        mScenes.erase(label);
    }
}

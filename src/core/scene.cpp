#include <vane/core/scene.hpp>
#include <vane/core/object.hpp>
#include <vane/core/log.hpp>

using namespace vane;


GameScene::GameScene( const std::string &label )
:   mLabel(label)
{
    
}


GameObject *GameScene::createObject()
{
    int   id  = int(mObjects.size());
    auto *obj = new GameObject(this, id);
    mObjects.insert(obj);

    return obj;
}


void GameScene::destroyObject( GameObject *obj )
{
    VANE_ASSERT(mObjects.contains(obj), "No such object!");
    mObjects.erase(obj);
    delete obj;
}

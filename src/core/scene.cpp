#include "scene.hpp"
#include "object.hpp"

using namespace vane;


GameObject *GameScene::createObject()
{
    int   id  = int(mObjects.size());
    auto *obj = new GameObject(id);
}


void GameScene::destroyObject( GameObject *obj )
{
    if (mFreeList.contains(obj->mId))
    {
        
    }

    else
    {
        // error
    }
}

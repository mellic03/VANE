#include <vane/core/object.hpp>

using namespace vane;


GameObjectAttr::GameObjectAttr( GameObject *obj )
:   mObject(obj)
{

}


GameObject::GameObject( GameScene *scene )
:   mScene(scene)
{

}


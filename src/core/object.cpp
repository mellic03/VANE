#include <vane/core/object.hpp>

using namespace vane;


GameObject::GameObject( GameScene *scene )
:   mScene(scene)
{
    mAttrs.fill(ObjAttr_None);
}

bool GameObject::hasAttr( ObjAttr_ attr )
{
    return mAttrs[attr] != ObjAttr_None;
}

int GameObject::addAttr( ObjAttr_ attr )
{
    if (hasAttr(attr))
        return ObjAttr_None;

    // mAttrs[attr] = someFunction();

    return mAttrs[attr];
}

int GameObject::rmAttr( ObjAttr_ attr )
{

}


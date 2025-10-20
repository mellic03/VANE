#pragma once

#include "types.hpp"
#include "scenegroup.hpp"
#include <set>


class vane::GameScene: public vane::SceneGroup
{
public:
    GameObject *createObject();
    void destroyObject( GameObject* );

private:
    friend class vane::SceneGroup;
    std::string           mLabel;
    std::set<GameObject*> mObjects;
    GameScene( const std::string &label );
};


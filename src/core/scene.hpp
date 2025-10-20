#pragma once
#include <vector>
#include <set>

namespace vane
{
    class GameScene;
    class GameObject;
}


class vane::GameScene
{
public:
    GameObject *createObject();
    void destroyObject( GameObject* );

private:
    std::set<int> mFreeList;
    std::set<GameObject*> mObjects;

};


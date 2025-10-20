#pragma once

#include "types.hpp"
#include <vector>
#include <set>
#include <string>


class vane::GameScene
{
public:
    friend class vane::Game;
    GameObject *createObject();
    void destroyObject( GameObject* );

private:
    std::string mLabel;
    std::set<GameObject*> mObjects;
    GameScene( const std::string &label );

};


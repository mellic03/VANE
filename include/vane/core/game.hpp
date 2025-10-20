#pragma once

#include "types.hpp"
#include <set>
#include <string>


class vane::Game
{
public:
    GameScene *createScene( const std::string &label );
    void destroyScene( GameScene* );

private:
    std::set<GameScene*> mScenes;

};


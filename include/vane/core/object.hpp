#pragma once

#include "types.hpp"


class vane::GameObject
{
public:
    friend class vane::GameScene;

private:
    GameScene *mScene;
    int        mId;
    GameObject( GameScene*, int id );
    virtual ~GameObject() = default;
};


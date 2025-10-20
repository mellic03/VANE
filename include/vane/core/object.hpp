#pragma once

#include "types.hpp"


class vane::GameObject
{
protected:
    GameScene *mScene;

private:
    friend class GameScene;
    GameObject( GameScene *sc ): mScene(sc) {  }
    virtual ~GameObject() = default;
};

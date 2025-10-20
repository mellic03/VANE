#pragma once

namespace vane
{
    class GameScene;
    class GameObject;
}


class vane::GameObject
{
public:
    friend class vane::GameScene;

private:
    int mId;
    GameObject( int id );
};

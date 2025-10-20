#pragma once

#include "types.hpp"
// #include "objattr.hpp"
#include <vane/vec.hpp>
#include <vector>
#include <string>


class vane::GameObjectAttr
{
public:
    GameObjectAttr( GameObject *obj );
    virtual ~GameObjectAttr() = default;

protected:
    GameObject *mObject;
};


class vane::GameObject
{
private:
    std::vector<GameObjectAttr*> mAttrs;

public:
    template <typename attr_type, typename... Args>
    void giveAttr( Args&&... args )
    {
        mAttrs.push_back(new attr_type(this, std::move(args...)));
    }

protected:
    friend class GameScene;
    GameScene *mScene;

    GameObject( GameScene* );
    virtual ~GameObject() = default;

};



// class vane::PhysObject: public vane::GameObject
// {
// public:
//     PhysObject(GameScene *scene, const vec3 &pos)
//     :   GameObject(scene), mPos(pos), mVel(0.0f), mAcc(0.0f) {  }

// private:
//     vec3 mPos, mVel, mAcc;
// };



// class vane::AudioObject: public vane::GameObject
// {
// public:
//     AudioObject(GameScene *scene, const std::string &path)
//     :   GameObject(scene), mPath(path) {  }

// private:
//     const std::string mPath;

// };



// class vane::ScriptObject: public vane::GameObject
// {
// public:
//     ScriptObject(GameScene *scene, const std::string &path)
//     :   GameObject(scene), mPath(path) {  }

// private:
//     const std::string mPath;
// };

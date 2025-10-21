#pragma once

#include "types.hpp"
#include <vane/vec.hpp>
#include <vector>
#include <string>


class vane::GameObject
{
private:
    std::vector<ObjAttr*> mAttrs;

protected:
    GameScene *mScene;

public:
    GameObject( GameScene* );
    virtual ~GameObject() = default;

    template <typename attr_type, typename... Args>
    void giveAttr( Args... args )
    {
        mAttrs.push_back(new attr_type(this, args...));
    }

};


class vane::ObjAttr
{
public:
    ObjAttr( GameObject* );
    virtual ~ObjAttr() = default;

protected:
    GameObject *mObject;
};


class vane::ObjAttrTransform: public ObjAttr
{
public:
    vec3 mPos, mVel, mAcc;

    ObjAttrTransform( GameObject *obj, const vec3 &pos = vec3(0.0f) )
    :   ObjAttr(obj), mPos(pos), mVel(0.0f), mAcc(0.0f) {  }
};



class vane::ObjAttrRigidBody: public ObjAttrTransform
{
public:
    ObjAttrRigidBody( GameObject *obj, const vec3 &pos = vec3(0.0f) )
    :   ObjAttrTransform(obj, pos) {  }
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

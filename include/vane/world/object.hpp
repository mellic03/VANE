#pragma once

#include <vane/util/reliant.hpp>
#include <vane/vec.hpp>
#include <vector>
#include <string>


// namespace vane
// {
//     struct ObjectID {
//         uint32_t type :16;
//         int32_t  idx  :48;
//     } __attribute__((packed));

//     template <typename T>
//     class ObjectAllocator;
// }


// template <typename T>
// class vane::ObjectAllocator
// {
// public:
//     struct 

// private:
    
// };





namespace vane
{
    class GameWorld;
    class GameObject;
    class ComponentTransform;
    class ComponentRigidBody;
}



class vane::GameObject: public util::Reliant<GameWorld>
{
public:
    struct Component: public util::Reliant<GameObject>
    { Component( GameObject &obj ): Reliant(obj) {  } };
    std::vector<Component*> mAttrs;

    GameObject( GameWorld &W ): Reliant<GameWorld>(W) {  }
    virtual ~GameObject() = default;

    void giveComponent( Component *c ) { mAttrs.push_back(c); }

private:

};




class vane::ComponentTransform: public GameObject::Component
{
public:
    vec3 mPos, mVel, mAcc;

    ComponentTransform( GameObject &obj, const vec3 &p = vec3(0.0f) )
    :   Component(obj), mPos(p), mVel(0.0f), mAcc(0.0f) {  }
};


class vane::ComponentRigidBody: public GameObject::Component
{
public:
    ComponentRigidBody( GameObject &obj )
    :   Component(obj) {  }
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

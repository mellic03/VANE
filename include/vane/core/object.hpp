#pragma once

#include "types.hpp"
#include <vane/vec.hpp>
#include <array>


enum vane::ObjAttr_: int
{
    ObjAttr_None = -1,
    ObjAttr_Transform = 0,
    ObjAttr_Physics,
    ObjAttr_Audio,
    ObjAttr_Script,
    ObjAttr_NumAttrs
};


class vane::GameObject
{
public:
    bool hasAttr( ObjAttr_ );

    /**
     * @return Attr idx, error if ObjAttr_None.
     */
    int addAttr( ObjAttr_ );

    /**
     * @return ObjAttr_None, error otherwise.
     */
    int rmAttr( ObjAttr_ );

protected:
    friend class GameScene;
    GameScene *mScene;

    GameObject( GameScene* );
    virtual ~GameObject() = default;

private:
    std::array<int, ObjAttr_NumAttrs> mAttrs;

};



class vane::PhysObject: public vane::GameObject
{
public:
    PhysObject(GameScene *scene, const vec3 &pos)
    :   GameObject(scene), mPos(pos), mVel(0.0f), mAcc(0.0f) {  }

private:
    vec3 mPos, mVel, mAcc;
};



class vane::AudioObject: public vane::GameObject
{
public:
    AudioObject(GameScene *scene, const std::string &path)
    :   GameObject(scene), mPath(path) {  }

private:
    const std::string mPath;

};



class vane::ScriptObject: public vane::GameObject
{
public:
    ScriptObject(GameScene *scene, const std::string &path)
    :   GameObject(scene), mPath(path) {  }

private:
    const std::string mPath;
};

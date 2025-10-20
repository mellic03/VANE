#pragma once

#include "types.hpp"
#include <vector>
#include <map>
#include <set>
#include <string>



template <typename key_type, typename obj_type>
class GroupType;


template <typename obj_type>
class GroupType<void, obj_type>
{
public:
    GameScene *createScene( const std::string &label );
    GameScene *getScene( const std::string &label );
    void destroyScene( const std::string &label );
    void destroyScene( vane::GameScene* );
private:
    std::map<std::string, GameScene*> mScenes;
};

// class vane::GameSceneGroup
// {
// public:
//     GameScene *createScene( const std::string &label );
//     GameScene *getScene( const std::string &label );
//     void destroyScene( const std::string &label );
//     void destroyScene( vane::GameScene* );
// private:
//     std::map<std::string, GameScene*> mScenes;
// };


class vane::GameScene: public GameSceneGroup
{
    friend class vane::GameSceneGroup;

public:
    GameObject *createObject();
    void destroyObject( GameObject* );

private:
    std::string           mLabel;
    std::set<GameObject*> mObjects;
    GameScene( const std::string &label );

};

#pragma once

#include "types.hpp"
#include <map>
#include <string>


class vane::SceneGroup
{
public:
    GameScene *createScene( const std::string &label );
    GameScene *getScene( const std::string &label );
    void destroyScene( const std::string &label );
    void destroyScene( vane::GameScene* );
private:
    std::map<std::string, GameScene*> mScenes;
};



/*
#define VANE_OBJECT_GROUP(Name_, Label_, ObjType_, KeyType_) \
    template <typename obj_type, typename key_type> \
    class Name_##_BaseType { \
    private: \
        std::map<key_type, obj_type*> m##Label_##s; \
    public: \
        obj_type *create ##Label_( const key_type &key ) { \
            auto &map = m##Label_##s; \
            map[key] = new GameScene(key); \
            return map[key]; \
        } \
        obj_type *get ##Label_( const key_type &key ) { \
            auto &map = m##Label_##s; \
            return (map.contains(key)) ? map[key] : nullptr; \
        } \
        void destroy ##Label_( const key_type &key ) { \
            auto &map = m##Label_##s; \
            map.erase(key); \
        } \
        auto &get##Label_##s() { return m##Label_##s; } \
    }; \
    \
    template <typename obj_type> \
    class Name_##_BaseType<obj_type, void> \
    { \
    public: \
        obj_type *create ##Label_() { \
            auto *obj = new obj_type(); \
            m##Label_##s.insert(obj); \
            return obj; \
        } \
        void destroy ##Label_( obj_type *obj ) { m##Label_##s.erase(obj); } \
        auto &get##Label_##s() { return m##Label_##s; } \
    private: \
        std::set<obj_type*> m##Label_##s; \
    }; \
    class Name_: public Name_##_BaseType<ObjType_, KeyType_> {  }
*/

/*
    template <typename... Args> \
    obj_type *create ##Label_( Args... args ) { \
        auto *obj = new obj_type(args...); \
        m##Label_##s.insert(obj); \
        return obj; \
    } \
*/

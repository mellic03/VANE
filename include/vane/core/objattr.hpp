// #pragma once

// #include "types.hpp"
// #include "assert.hpp"
// #include <vane/vec.hpp>
// #include <array>
// #include <stack>

// namespace vane
// {
//     class ObjAttr
//     {
//     public:
        
//     private:
    
//     };
    
//     enum ObjAttr_: int
//     {
//         ObjAttr_None = -1,
//         ObjAttr_Transform = 0,
//         ObjAttr_RigidBody,
//         ObjAttr_SoftBody,
//         ObjAttr_Audio,
//         ObjAttr_Script,
//         ObjAttr_NumAttrs,
//         ObjAttr_MaxAttrs = 64
//     };

//     struct ObjAttrTransform;
//     struct ObjAttrRigidBody;
//     struct ObjAttrSoftBody;
//     struct ObjAttrAudio;
//     struct ObjAttrScript;

//     class ObjectAttrManager;
// }


// struct vane::ObjAttrTransform
// {
//     vec3 mPos, mVel, mAcc;
// };

// struct vane::ObjAttrRigidBody: public ObjAttrTransform
// {

// };

// struct vane::ObjAttrSoftBody: public ObjAttrTransform
// {

// };

// struct vane::ObjAttrAudio
// {

// };

// struct vane::ObjAttrScript
// {

// };


// class vane::ObjectAttrManager
// {
// public:
//     int newAttr( ObjAttr_ );
//     void freeAttr( ObjAttr_, int );
//     void *getAttr( ObjAttr_ attr, int idx );

//     template <typename T>
//     T &getAttr( ObjAttr_ attr, int idx )
//     {
//         return *static_cast<T*>(getAttr(attr, idx));
//     }

//     template <typename T>
//     struct AttrArray
//     {
//     private:
//         std::array<T, ObjAttr_MaxAttrs> mObjects;
//         std::stack<int> mFreelist;

//     public:
//         AttrArray();
//         int create();
//         void destroy( int idx );
//         T &operator[](int i) { return mObjects[i]; }
//     };

// private:
//     AttrArray<ObjAttrTransform> mTransform;
//     AttrArray<ObjAttrRigidBody> mRigidBody;
//     AttrArray<ObjAttrSoftBody>  mSoftBody;
//     AttrArray<ObjAttrAudio>     mAudio;
//     AttrArray<ObjAttrScript>    mScript;
// };





// template <typename T>
// vane::ObjectAttrManager::AttrArray<T>::AttrArray()
// {
//     for (int i=ObjAttr_MaxAttrs-1; i>=0; i--)
//     {
//         mFreelist.push(i);
//     }
// }

// template <typename T>
// int vane::ObjectAttrManager::AttrArray<T>::create()
// {
//     VANE_ASSERT(!mFreelist.empty(), "Out of space!");
//     int idx = mFreelist.top(); mFreelist.pop();
//     mObjects[idx] = T();
//     return idx;
// }

// template <typename T>
// void vane::ObjectAttrManager::AttrArray<T>::destroy( int idx )
// {
//     mObjects[idx].~T();
//     mFreelist.push(idx);
// }


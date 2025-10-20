// #include <vane/core/objattr.hpp>
// #include <vane/core/log.hpp>

// using namespace vane;


// int ObjectAttrManager::newAttr( ObjAttr_ attr )
// {
//     switch (attr)
//     {
//         case ObjAttr_Transform: return mTransform.create();
//         case ObjAttr_RigidBody: return mRigidBody.create();
//         case ObjAttr_SoftBody:  return mSoftBody.create();
//         case ObjAttr_Audio:     return mAudio.create();
//         case ObjAttr_Script:    return mScript.create();
//         default: VANE_ASSERT(false, "Should be unreachable!"); break;
//     }
//     return ObjAttr_None;
// }

// void ObjectAttrManager::freeAttr( ObjAttr_ attr, int idx )
// {
//     switch (attr)
//     {
//         case ObjAttr_Transform: mTransform.destroy(idx); break;
//         case ObjAttr_RigidBody: mRigidBody.destroy(idx); break;
//         case ObjAttr_SoftBody:  mSoftBody.destroy(idx);  break;
//         case ObjAttr_Audio:     mAudio.destroy(idx);     break;
//         case ObjAttr_Script:    mScript.destroy(idx);    break;
//         default: VANE_ASSERT(false, "Should be unreachable!"); break;
//     }
// }

// void *ObjectAttrManager::getAttr( ObjAttr_ attr, int idx )
// {
//     switch (attr)
//     {
//         case ObjAttr_Transform: return (void*)(&mTransform[idx]);
//         case ObjAttr_RigidBody: return (void*)(&mRigidBody[idx]);
//         case ObjAttr_SoftBody:  return (void*)(&mSoftBody[idx]);
//         case ObjAttr_Audio:     return (void*)(&mAudio[idx]);
//         case ObjAttr_Script:    return (void*)(&mScript[idx]);
//         default: VANE_ASSERT(false, "Should be unreachable!"); break;
//     }
//     return nullptr;
// }


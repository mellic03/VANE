#include <vane/world/world.hpp>
#include <vane/core/assert.hpp>

using namespace vane;


void GameWorld::update()
{
    for (auto *S: mServices)
    {
        S->update();
    }
}



GameObject *GameWorld::addObject()
{
    mObjects.push_back(GameObject(*this));
}


GameService *GameWorld::addService( GameService *srv )
{
    mServices.push_back(srv);
    return srv;
}


// bool GameWorld::killObject( GameObject *obj )
// {
//     VANE_ASSERT(&mObjects[0] <= obj, "Invalid pointer!");
//     VANE_ASSERT(obj <= &(mObjects.back()), "Invalid pointer!");
//     auto *beg = mObjects.data();
//     auto *end = beg + mObjects.size();
//     int   idx = obj - mObjects.data();

//     GameObject tmp = mObjects[idx];
//     mObjects.push_back(GameObject(*this));
// }

// bool GameWorld::killService( GameService *srv )
// {
//     // VANE_ASSERT(&mServices[0] <= srv, "Invalid pointer!");
//     // VANE_ASSERT(srv <= &(mServices.back()), "Invalid pointer!");
//     // auto *beg = mServices.data();
//     // auto *end = beg + mServices.size();
//     // int   idx = srv - mServices.data();
//     // mServices.push_back(new GameService(*this));
// }

#pragma once

#include "object.hpp"
#include "scene.hpp"
#include "service.hpp"


class vane::GameWorld
{
private:
    std::vector<GameObject>   mObjects;    
    std::vector<GameService*> mServices;    

public:
    GameWorld( size_t obj_limit )
    {
        mObjects.reserve(obj_limit);
    }

    void update();

    GameObject *addObject();
    GameService *addService( GameService* );
    
    bool killObject( GameObject* );
    bool killService( GameService* );

};

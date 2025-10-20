#pragma once

#include "types.hpp"
#include <map>
#include <string>


class vane::Game: public vane::EngineRef
{
public:
    Game( vane::Engine &e ): EngineRef(e) {  };
    virtual ~Game() = default;
    virtual void update() = 0;

    GameScene *createScene( const std::string &label );
    GameScene *getScene( const std::string &label );
    void destroyScene( const std::string &label );
    void destroyScene( GameScene* );

protected:
    std::map<std::string, GameScene*> mScenes;

};


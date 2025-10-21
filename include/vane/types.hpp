#pragma once
#include "stdint.hpp"

namespace vane
{
    class Engine;
    class EngineRef;
}

class vane::EngineRef
{
public:
    EngineRef( vane::Engine &e ): mEngine(e) {  };

protected:
    vane::Engine &mEngine;
};


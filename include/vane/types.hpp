#pragma once
#include "stdint.hpp"

namespace vane
{
    template <typename T>
    class Reliant
    {
    private:
        T &mObj;
    public:
        Reliant( const T &x ): mObj(x) {  }
    };

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


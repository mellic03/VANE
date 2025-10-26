#pragma once

#include <vane/core/service.hpp>

namespace vane
{
    class GfxService;
}


class vane::GfxService: public VaneService
{
public:
    using VaneService::VaneService;

    virtual void update() override;
    virtual void preUpdate() override;
    virtual void postUpdate() override;

};

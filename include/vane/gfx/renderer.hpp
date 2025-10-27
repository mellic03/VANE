#pragma once

#include <cstddef>
#include <cstdint>

namespace vane::gfx
{
    struct RenderProgram;
    class Renderer;
}


struct vane::gfx::RenderProgram
{
    enum prog_type: uint8_t
    {
        is_none=0, is_glsl, is_spirv,
    };

    struct prog_glsl
    {
        char path[128];
    };

    struct prog_spirv
    {
        uint8_t *base;
        uint32_t size;
    };

    prog_type  type;

    union {
        prog_glsl  as_glsl;
        prog_spirv as_spirv;
    };
};


void testtesttest()
{
    vane::gfx::RenderProgram prog;
    // prog.as_spirv.base
}


class vane::gfx::Renderer
{
public:
    Renderer();

private:

};


#pragma once

#include <cstdint>
#include <cstddef>

using int8   = int8_t;
using int16  = int16_t;
using int32  = int32_t;
using int64  = int64_t;

using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;


namespace vane
{
    static constexpr size_t MONO = 1;
    static constexpr size_t KILO = 1024;
    static constexpr size_t MEGA = 1024*KILO;
    static constexpr size_t GIGA = 1024*MEGA;
}

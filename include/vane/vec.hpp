#pragma once

#include <stddef.h>
#include <stdint.h>

namespace vane
{
    template <size_t N, typename T>
    struct vec;

    template <typename T>
    struct vec<1, T>
    {
        union { T x, r; };

        template <typename U>
        vec<1, T> operator+( const vec<1, U> &v )
        {
            return vec<1, T>{
                x + static_cast<T>(v.x)
            };
        }
    };

    template <typename T>
    struct vec<2, T>: public vec<1, T>
    {
        union { T y, g; };

        template <typename U>
        vec<2, T> operator+( const vec<2, U> &v )
        {
            return vec<2, T>{
                this->x + static_cast<T>(v.x),
                this->y + static_cast<T>(v.y)
            };
        }
    };

    template <typename T>
    struct vec<3, T>: public vec<2, T>
    {
        union { T z, b; };

        template <typename U>
        vec<3, T> operator+( const vec<3, U> &v )
        {
            return vec<3, T>{
                this->x + static_cast<T>(v.x),
                this->y + static_cast<T>(v.y),
                this->z + static_cast<T>(v.z)
            };
        }
    };

    template <typename T>
    struct vec<4, T>: public vec<3, T>
    {
        union { T w, a; };

        template <typename U>
        vec<4, T> operator+( const vec<4, U> &v )
        {
            return vec<4, T>{
                this->x + static_cast<T>(v.x),
                this->y + static_cast<T>(v.y),
                this->z + static_cast<T>(v.z),
                this->w + static_cast<T>(v.w)
            };
        }

        // T &operator[](int i)
        // {
        //     switch (i)
        //     {
        //         default: return x;
        //         case 0: return x;
        //         case 1: return y;
        //         case 2: return vec<3, T>::z;
        //         case 3: return w;
        //     }
        // }
    };

    using ivec2 = vec<2, int>;
    using ivec3 = vec<2, int>;
    using ivec4 = vec<3, int>;

    using uvec2 = vec<2, uint32_t>;
    using uvec3 = vec<3, uint32_t>;
    using uvec4 = vec<4, uint32_t>;
}


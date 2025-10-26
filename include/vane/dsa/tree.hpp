#pragma once

#include <cstddef>
#include <cstdint>
#include <vane/vec.hpp>

namespace vane::DSA
{
    template <size_t N_>
    class TreeNode;
}


template <size_t N_>
class vane::DSA::TreeNode
{
public:
    void insert( const vec3&, void* );
    TreeNode &operator[]( int i );

private:
    static constexpr size_t N = N_;
    int mNodes[N_];
};


#include "tree.inl"

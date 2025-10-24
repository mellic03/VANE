#pragma once

#include <cstddef>
#include <cstdint>

#include "set.hpp"


namespace vane::DSA
{
    // template <typename T>
    class pool_allocator
    {
    public:
        pool_allocator( void *base, size_t size, size_t stride );

        template <typename dype>
        dype *alloc( size_t n ) { return new (alloc(n)) dype(); }
        void *alloc( size_t n );
        void  free( void *p );

    private:
        uint8_t *mBase;
        size_t   mSize;
        size_t   mStride;

    };
}


namespace vane::DSA
{
    class Node
    {
    private:
        ctig_set<Node*> mChildren;
        void _bfsForEach( void (*callback)(Node*) );

    public:
        void bfsForEach( void (*callback)(Node*) );
        void dfsForEach( void (*callback)(Node*) );

    };
}


template <size_t N_>
class TreeNode
{
private:
    static constexpr size_t N = N_;
    TreeNode<N_> nodes[N_];
};

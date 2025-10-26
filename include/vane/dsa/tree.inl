#pragma once

#include "tree.hpp"
#define NodeType vane::DSA::TreeNode


template <size_t N_>
NodeType<N_> &NodeType<N_>::operator[]( int i )
{
    return mNodes[i];
}



#undef NodeType

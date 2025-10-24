#include <vane/dsa/node.hpp>

using namespace vane;



void DSA::Node::_bfsForEach( void (*callback)(Node*) )
{
    for (auto &nd: mChildren)
    {
        callback(nd);
    }

    for (auto &nd: mChildren)
    {
        nd->_bfsForEach(callback);
    }
}

void DSA::Node::bfsForEach( void (*callback)(Node*) )
{
    callback(this);
    _bfsForEach(callback);
}


void DSA::Node::dfsForEach( void (*callback)(Node*) )
{
    callback(this);

    for (auto &nd: mChildren)
    {
        nd->dfsForEach(callback);
    }
}


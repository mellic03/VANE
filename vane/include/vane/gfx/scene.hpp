#pragma once

#include <vane/dsa/node.hpp>

namespace vane::gfx
{
    class SceneGraph;
}


class vane::gfx::SceneGraph
{
public:

private:
    class Node: public DSA::Node
    {
    public:
        Node() {  };
    };

    std::vector<Node> mNodes;

};


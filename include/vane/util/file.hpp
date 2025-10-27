#pragma once

#include <vane/core/assert.hpp>
#include <fstream>
#include <string>
#include <vector>

namespace vane
{
    inline static
    std::string loadRaw( const std::string &path )
    {
        std::ifstream stream(path, std::ifstream::binary);
        VANE_ASSERT(stream.is_open(), "Failed opening file \"%s\"", path.c_str());

        stream.seekg(0, std::ifstream::end);
        std::string buf; buf.resize(stream.tellg());

        stream.seekg(0, std::ifstream::beg);
        stream.read((char*)(buf.data()), buf.size());

        return buf;
    }
}

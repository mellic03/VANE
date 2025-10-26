#include <vane/util/file.hpp>
#include <vane/core/assert.hpp>
#include <fstream>

std::string vane::loadRaw( const std::string &path )
{
    std::ifstream stream(path, std::ifstream::binary);
    VANE_ASSERT(stream.is_open(), "Failed opening file \"%s\"", path.c_str());

    stream.seekg(0, std::ifstream::end);
    std::string buf; buf.resize(stream.tellg());

    stream.seekg(0, std::ifstream::beg);
    stream.read((char*)(buf.data()), buf.size());

    return buf;
}

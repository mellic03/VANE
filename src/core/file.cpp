#include <vane/core/file.hpp>
#include <vane/core/assert.hpp>
#include <fstream>

using namespace vane;


// std::vector<uint8> vane::loadRaw( const std::string &path )
// {
//     std::ifstream stream(path, std::ifstream::binary);
//     VANE_ASSERT(stream.is_open(), "Cannot open file \"%s\"", path.c_str());

//     stream.seekg(0, std::ifstream::end);
//     std::vector<uint8> buf(stream.tellg());

//     stream.seekg(0, std::ifstream::beg);
//     stream.read((char*)(buf.data()), buf.size());

//     return buf;
// }


std::string vane::loadRaw( const std::string &path )
{
    std::ifstream stream(path, std::ifstream::binary);
    VANE_ASSERT(stream.is_open(), "Cannot open file \"%s\"", path.c_str());

    stream.seekg(0, std::ifstream::end);
    std::string buf; buf.resize(stream.tellg());

    stream.seekg(0, std::ifstream::beg);
    stream.read((char*)(buf.data()), buf.size());

    return buf;
}

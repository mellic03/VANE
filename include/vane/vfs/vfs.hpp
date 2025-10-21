#pragma once

#include <vane/stdint.hpp>
#include <string>


namespace vane::vfs
{
    static constexpr size_t KILO = 1024;
    static constexpr size_t MEGA = 1024*KILO;
    static constexpr size_t BLOCK_SIZE = 4*KILO;

    using DataBlock = uint8[BLOCK_SIZE];

    struct RootHeader {
        size_t count;
        uint8  padding[BLOCK_SIZE - sizeof(size_t)];
    } __attribute__((packed));

    struct RootTable {
        RootHeader header;
        DataBlock  files[4];
        DataBlock  blocks[1];
    } __attribute__((packed));

    struct FileNode {
        char name[32];
        uint32 count;
        uint32 blocks[24-1];
    } __attribute__((packed));

    class FileSystem
    {
    public:
        FileSystem( size_t blocks );
        FileNode *find( const std::string &name );
        FileNode *open( const std::string &name );
        size_t write( const std::string &name, const void *src, size_t size );
        size_t read( const std::string &name, void *dst, size_t size );

    private:
        RootTable *mTable;
 
    };

}

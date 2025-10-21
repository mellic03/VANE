#pragma once

#include <vane/stdint.hpp>
#include <string>


namespace vane::vfs
{
    static constexpr size_t KILO = 1024;
    static constexpr size_t MEGA = 1024*KILO;
    static constexpr size_t BLOCK_SIZE = 4*KILO;

    struct DataBlock {
        uint64 avail;
        uint8  data[BLOCK_SIZE - sizeof(uint64)];
    } __attribute__((packed));

    struct RootTable {
        uint32     nblocks;
        uint8      padding[BLOCK_SIZE - sizeof(size_t)];
        DataBlock  files[4];
        DataBlock  blocks[4];
    } __attribute__((packed));

    struct FileNode {
        char name[32];
        uint32 nblocks;
        uint32 rdpos;
        uint32 wtpos;
        uint32 blocks[24-3];
    } __attribute__((packed));

    class FileSystem
    {
    public:
        FileSystem( size_t nblocks=512 );
        FileNode *open( const std::string &name );
        size_t write( FileNode*, const void *src, size_t size );
        size_t read( FileNode*, void *dst, size_t size );

    private:
        RootTable *mTable;
        FileNode  *mFileBeg, *mFileEnd;
        DataBlock *mDataBeg, *mDataEnd;
        FileNode  *findFileNode( const std::string &name );
        FileNode  *newFileNode( const std::string &name );
        uint32     newDataBlock();
    };

}

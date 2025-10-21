#include <vane/vfs/vfs.hpp>
#include <cstdlib>

using namespace vane;


vfs::FileSystem::FileSystem( size_t blocks )
:   mTable((RootTable*)malloc(BLOCK_SIZE*blocks))
{
    
}

vfs::FileNode *vfs::FileSystem::find( const std::string &name )
{
    uint8 *base = (uint8*)(mTable->files);
    FileNode *beg = (FileNode*)(base);
    FileNode *end = (FileNode*)(base + sizeof(mTable->files));

    for (FileNode *file=beg; file<end; file++)
    {
        if (std::string(file->name) == name)
        {
            return file;
        }
    }

    return nullptr;
}

vfs::FileNode *vfs::FileSystem::open( const std::string &name )
{
    FileNode *file = find(name);
    if (file) return file;

    // uint8 *base = (uint8*)(mTable->files);
    // FileNode *beg = (FileNode*)(base);
    // FileNode *end = (FileNode*)(base + sizeof(mTable->files));

    // for (FileNode *file=beg; file<end; file++)
    // {

    // }
    return nullptr;
}

size_t vfs::FileSystem::write( const std::string &name, const void *src, size_t size )
{

}

size_t vfs::FileSystem::read( const std::string &name, void *dst, size_t size )
{

}


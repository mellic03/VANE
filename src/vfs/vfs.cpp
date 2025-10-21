#include <vane/vfs/vfs.hpp>
#include <cstdlib>
#include <cstring>

using namespace vane;


vfs::FileSystem::FileSystem( size_t nblocks )
{
    using RT = RootTable;

    mTable = (RootTable*)malloc(
          sizeof(RT::nblocks) + sizeof(RT::padding)
        + sizeof(RT::files) + nblocks*sizeof(DataBlock)
    );

    uint8 *fbase = (uint8*)(mTable->files);
    mFileBeg = (FileNode*)(fbase);
    mFileEnd = (FileNode*)(fbase + sizeof(mTable->files));

    uint8 *dbase = (uint8*)(mTable->blocks);
    mDataBeg = (DataBlock*)(dbase);
    mDataEnd = (DataBlock*)(dbase + nblocks*sizeof(DataBlock));

    for (FileNode *F=mFileBeg; F<mFileEnd; F++)
    {
        memset(F, '\0', sizeof(FileNode));
    }

    for (DataBlock *B=mDataBeg; B<mDataEnd; B++)
    {
        B->avail = 1;
    }
}


vfs::FileNode *vfs::FileSystem::open( const std::string &name )
{
    FileNode *file = findFileNode(name);
    if (file) return file;
    return newFileNode(name);
}


size_t vfs::FileSystem::write( FileNode *F, const void *src, size_t size )
{
    if (F->nblocks == 0)
    {
        uint32 idx = newDataBlock();
        F->nblocks   = 1;
        F->blocks[0] = idx;
    }

    uint8 *srcpos = (uint8*)src;
    uint8 *srcend = srcpos + size;
    size_t total  = 0;

    while (srcpos<srcend && F->nblocks<22)
    {
        uint32 blockno = F->wtpos / sizeof(DataBlock);
        if (blockno >= F->nblocks)
        {
            F->blocks[blockno] = newDataBlock();
            F->nblocks += 1;
        }

        uint32 idx = F->blocks[blockno];
        uint32 off = F->wtpos % sizeof(DataBlock);

        auto *B = (mTable->blocks + idx);
        B->data[off] = *(srcpos++);

        F->wtpos++;
    }

    return total;
}


size_t vfs::FileSystem::read( FileNode *F, void *dst, size_t size )
{
    uint8 *dstpos = (uint8*)dst;
    uint8 *dstend = dstpos + size;
    size_t total  = 0;

    while ((dstpos<dstend))
    {
        uint32 blockno = F->rdpos / sizeof(DataBlock);
        if (blockno >= F->nblocks)
        {
            break;
        }

        uint32 idx = F->blocks[blockno];
        uint32 off = F->rdpos % sizeof(DataBlock);

        auto *B = (mTable->blocks + idx);
        *(dstpos++) = B->data[off];

        F->rdpos++;
    }

    return total;
}



vfs::FileNode *vfs::FileSystem::findFileNode( const std::string &name )
{
    for (FileNode *F=mFileBeg; F<mFileEnd; F++)
    {
        if (std::string(F->name) == name)
        {
            return F;
        }
    }
    return nullptr;
}


vfs::FileNode *vfs::FileSystem::newFileNode( const std::string &name )
{
    for (FileNode *F=mFileBeg; F<mFileEnd; F++)
    {
        if (F->name[0] == '\0')
        {
            strncpy(F->name, name.c_str(), sizeof(F->name)-1);
            return F;
        }
    }
    return nullptr;
}


uint32 vfs::FileSystem::newDataBlock()
{
    for (DataBlock *B=mDataBeg; B<mDataEnd; B++)
    {
        if (B->avail == 1)
        {
            B->avail = 0;
            return (B - mDataBeg) / sizeof(DataBlock);
        }
    }
    return 0;
}


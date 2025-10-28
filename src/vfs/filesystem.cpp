#include <vane/vfs/filesystem.hpp>
#include <vane/core/assert.hpp>
#include <vane/util/file.hpp>
#include <cstring>
#include <filesystem>


namespace vane
{
    struct FileImpl
    {
        void  *base;
        size_t size;
    };
}


vanefs::PkgFsReader::PkgFsReader( const char *pkgpath )
{
    std::filesystem::path path(pkgpath);
    VANE_ASSERT(std::filesystem::exists(path), "Failed to open file \"%s\"", pkgpath);
    mArchive.load(path.string());
}

bool vanefs::PkgFsReader::exists( const char *filepath )
{
    return (mArchive.open(filepath).data != nullptr);
}

vanefs::File vanefs::PkgFsReader::open( const char *filepath )
{
    auto F = mArchive.open(filepath);
    return new vane::FileImpl{F.data, F.size};
}

size_t vanefs::PkgFsReader::read( File fh, size_t offset, void *dst, size_t nbytes )
{
    auto *F = (vane::FileImpl*)fh;
    nbytes = std::min(F->size, nbytes);
    std::memcpy(dst, F->base, nbytes);
    return nbytes;
}

void *vanefs::PkgFsReader::base( File fh )
{
    return ((vane::FileImpl*)fh)->base;
}

size_t vanefs::PkgFsReader::size( File fh )
{
    return ((vane::FileImpl*)fh)->size;
}





bool vanefs::StdFsReader::exists( const char *filepath )
{
    return std::filesystem::exists(std::filesystem::path(filepath));
}

vanefs::File vanefs::StdFsReader::open( const char *filepath )
{
    return std::fopen(filepath, "r");
}

size_t vanefs::StdFsReader::read( File fh, size_t offset, void *dst, size_t n )
{
    return std::fread(dst, offset, n, (FILE*)fh);
}

size_t vanefs::StdFsWriter::write( File fh, size_t offset, void *src, size_t n )
{
    return std::fwrite(src, offset, n, (FILE*)fh);
}

#include <vane/vfs/archive.hpp>
#include <vane/core/log.hpp>
#include <vane/core/file.hpp>
#include <vane/core/assert.hpp>

#include <fstream>
#include <cstring>

using namespace vane;


constexpr size_t align_down( size_t x, size_t a )
{
    return x & ~(a-1);
}

constexpr size_t align_up( size_t x, size_t a )
{
    return (x + a-1) & ~(a-1);
}

static uint32_t ndigits( uint32_t x )
{
    uint32_t temp = abs(x); // Use absolute value for counting digits
    if (temp == 0)
    {
        return 1;
    }

    uint32_t count = 0;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }

    return count;
}



void PkgArchive::for_each( std::function<void(const FileHandle&)> fn )
{
    auto *base = &mBuf[0];
    auto *head = (RootHeader*)(base);
    auto *ftab = (FileTableEntry*)(base + head->offset);

    for (auto *F=ftab; F<ftab+head->count; F++)
    {
        fn(FileHandle(F->name, base+F->offset, F->size));
    }
}


void PkgArchive::add( const std::string &name, const void *src, size_t size )
{
    if (mFiles.contains(name))
    {
        // syslog log("PkgArchive::addFile");
        printf(
            "Warning: file \"%s\" already exists and will be overwritten!\n",
            name.c_str()
        );
    }

    mFiles[name].resize(size);
    std::memcpy(mFiles[name].data(), src, size);
}


void PkgArchive::save( const std::string &path )
{
    syslog log("PkgArchive::save");

    std::ofstream stream(path, std::ofstream::binary);
    VANE_ASSERT(stream.is_open(), "Failed opening file \"%s\"", path.c_str());

    auto [base, size] = _flush();
    stream.write((const char*)base, size);

    log("Writing %uB to %s...", size, path.c_str());
    log("Writing %uB to %s... done!", size, path.c_str());
    // {
    //     syslog log("ArchiveHeader");
    //     log("magic: \"%s\"", H->magic);
    //     log("offset: %u", H->offset);
    //     log("count:  %u", H->count);
    // }
}


void PkgArchive::load( const std::string &path )
{
    // syslog log("PkgArchive::load");
    mBuf = vane::loadRaw(path);
    // _printFileTable((uint8_t*)(&mBuf[0]));
}



std::pair<uint8_t*, size_t> PkgArchive::_flush()
{
    uint8_t *baseptr = nullptr;
    size_t   pkgsize = 0 + sizeof(RootHeader);

    for (auto &[name, data]: mFiles)
        pkgsize += data.size() + sizeof(FileTableEntry);
    baseptr = new uint8_t[pkgsize];

    uint32_t    fpos = sizeof(RootHeader); 
    RootHeader *head = (RootHeader*)baseptr;
    memcpy(head->magic, "vanepkg", 8);
    head->offset = fpos;
    head->count  = mFiles.size();

    // Incomplete file table
    auto *ftab = (FileTableEntry*)(baseptr + head->offset);

    for (auto &[name, data]: mFiles)
    {
        auto *F = (FileTableEntry*)(baseptr+fpos);
        memset(F->name, '\0', sizeof(F->name));
        strncpy(F->name, name.c_str(), sizeof(F->name)-1);
        F->offset = 0;
        F->size   = data.size();

        fpos += sizeof(FileTableEntry);
    }

    // File data
    std::map<std::string, uint32_t> fileOffset;
    for (auto &[name, data]: mFiles)
    {
        memcpy(baseptr+fpos, &data[0], data.size());
        fileOffset[name] = fpos;
        fpos += data.size();
    }

    // Complete file table
    for (size_t i=0; i<mFiles.size(); i++)
    {
        auto *F = &ftab[i];
        F->offset = fileOffset[std::string(F->name)];
    }

    mFiles.clear();
    return std::make_pair(baseptr, pkgsize);
}


void PkgArchive::_printFileTable( uint8_t *base )
{
    syslog log("PkgArchive::FileTable");

    auto *head = (RootHeader*)(base);
    auto *ftab = (FileTableEntry*)(base + head->offset);

    char temp1[sizeof(FileTableEntry::name) + 1];
    char temp2[sizeof(FileTableEntry::name) + 1];
    memset(temp1, '\0', sizeof(temp1));
    memset(temp2, '\0', sizeof(temp2));

    for (size_t i=0; i<mFiles.size(); i++)
    {
        auto *F = &ftab[i];

        if (i%50 == 0)
        {
            memset(temp1, '-', sizeof(temp1)-2);
            log("|-------------------------------%s", temp1);

            log("");
            log("| entry | offset   | size     | filename");
            log("|-------|----------|----------|%s|", temp1);
        }

        memset(temp1, '\0', sizeof(temp1));
        memset(temp2, '\0', sizeof(temp2));
        
        memset(temp1, ' ', 8-ndigits(F->size));
        memset(temp2, ' ', 56 - strnlen(F->name, 56));

        log(
            "| %04u  | %08u | %u%s | %s%s|",
            i, F->offset, F->size, temp1, F->name+2, temp2
        );
    }
    memset(temp1, '-', sizeof(temp1)-2);
    log("|-------------------------------%s", temp1);

}
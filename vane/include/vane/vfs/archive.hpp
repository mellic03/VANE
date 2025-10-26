#pragma once

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <functional>

namespace vane
{
    class  PkgArchive;
    struct PkgFile;
}


class vane::PkgArchive
{

private:
    std::string mBuf;
    std::map<std::string, std::vector<uint8_t>> mFiles;

    struct RootHeader {
        char     magic[8]; // "vanepkg";
        uint32_t offset;
        uint32_t count;
    } __attribute__((packed));

    struct FileTableEntry {
        char     name[56];
        uint32_t offset;
        uint32_t size;
    } __attribute__((packed));

    std::pair<uint8_t*, size_t> _flush();
    void _printFileTable( uint8_t *base );

public:

    struct FileHandle {
        const std::string name;
        const char *data;
        size_t size;

        FileHandle( const char *n, const char *d, size_t s )
        : name(n), data(d), size(s) {  };
    };

    void for_each( std::function<void(const FileHandle&)> );
    void add( const std::string&, const void *src, size_t size );
    void save( const std::string& );
    void load( const std::string& );

};

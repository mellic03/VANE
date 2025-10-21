#pragma once

#include <string>
#include <vector>


namespace vane::gfx
{
    class ShaderArchive;
}


class vane::gfx::ShaderArchive
{
public:
    void openArchive( const std::string& );
    void saveArchive( const std::string& );
    void addFile( const std::string& );
    void compileSPIRV( const std::string &src, const std::string &dst );

private:
    struct ArchiveHeader {
        size_t nshaders;
        size_t data[3];
    } __attribute__((packed));

    struct ArchiveData {
        size_t namesize;
        size_t datasize;
        size_t data[2];
    } __attribute__((packed));

    struct ShaderFile
    {
        std::string name;
        std::string data;
    };

    std::vector<ShaderFile> mShaders;
};

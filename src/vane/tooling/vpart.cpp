#include <vane/core/assert.hpp>
#include <vane/core/file.hpp>
#include <vane/stdint.hpp>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;


static std::vector<std::string> argvec;
static fs::path inpath;
static long blocksize;


bool check_args( int argc, char **argv )
{
    argvec.resize(argc-1);
    inpath = fs::path("./");
    blocksize = 1*1024;

    for (int i=1; i<argc; i++)
        argvec[i-1] = std::string(argv[i]);

    if (argvec.empty())
        return false;

    for (size_t i=0; i<argvec.size(); i++)
    {
        if (i+1 >= argvec.size())
        {
            continue;
        }

        auto &A = argvec[i+0];
        auto &B = argvec[i+1];

        if (A=="-i" || A=="--input")
        {
            inpath = argvec[++i];
        }

        else if (A=="--blocksize")
        {
            blocksize = std::stol(argvec[++i]);

            switch (B.back())
            {
                default: return false;
                case 'M': blocksize *= vane::MEGA; break;
                case 'K': blocksize *= vane::KILO; break;
                case 'B': blocksize *= vane::MONO; break;
            }
        }
    }

    return true;
}


int main( int argc, char **argv )
{
    if (!check_args(argc, argv))
    {
        printf(
            "Usage: vpart [OPTION]... [FILE]...\n"
            "  --input      specify input file.\n"
            "  --blocksize  specify block size.\n"
        );
        return 1;
    }

    VANE_ASSERT(fs::exists(inpath), "Invalid path \"%s\"", inpath.c_str());

    auto  buf = vane::loadRaw(inpath.string());
    auto *beg = (uint8_t*)(buf.data());
    auto *end = beg + buf.size();

    uint8_t *ptr = beg;
    size_t   idx = 0;

    while (ptr < end)
    {
        auto outpath = inpath.string() + ".vpart." + std::to_string(idx++);
        auto stream  = std::ofstream(outpath, std::ofstream::binary);

        size_t size = std::min(end-ptr, blocksize);
        printf("size: %lu\n", size);
        stream.write((const char*)ptr, size);

        ptr += blocksize;
    }
    // printf("input=%s, blocksize=%u, nblocks=%u\n", inpath.c_str(), blocksize);
    

}


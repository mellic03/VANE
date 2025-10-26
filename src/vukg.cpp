#include <vane/core/assert.hpp>
#include <vane/util/file.hpp>
#include <vane/vfs/archive.hpp>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;


static fs::path inpath;
static fs::path outpath;

bool check_args( int argc, char **argv )
{
    if (argc != 3)
        return false;

    inpath  = fs::path(argv[1]);
    outpath = fs::path(argv[2]);

    return true;
}


int main( int argc, char **argv )
{
    if (!check_args(argc, argv))
    {
        printf("Usage: vukg [INPUT] [OUTPUT]\n");
        return 1;
    }

    VANE_ASSERT(fs::exists(inpath), "Invalid path \"%s\"", inpath.c_str());
    // VANE_ASSERT(fs::exists(outpath), "Invalid path \"%s\"", outpath.c_str());

    if (fs::exists(outpath) == false)
    {
        fs::create_directories(outpath);
    }

    vane::PkgArchive PA;
    PA.load(inpath.string());

    PA.for_each([](const vane::PkgArchive::FileHandle &F)
    {
        fs::path filepath = outpath / fs::path(F.name);

        if (fs::exists(filepath) == false)
        {
            // if (fs::is_directory(filepath))
            //     fs::create_directories(filepath);
            // else
                fs::create_directories(filepath.parent_path());
        }

        printf("Writing %luB to %s\n", F.size, filepath.c_str());

        std::ofstream stream(filepath, std::ofstream::binary);
        stream.write(F.data, F.size);
        stream.close();
    });

    return 0;

    // if (argc==3 && std::string(argv[1])=="-l")
    // {
    //     PA.load(std::string(argv[2]));
    //     return 0;
    // }

    // for (int idx=1; idx<argc; idx++)
    // {
    //     std::string arg(argv[idx]);

    //     if (arg=="-v" || arg=="--verbose")
    //     {
    //         vpkg_verbose = true;
    //     }

    //     else if ((arg=="-i" || arg=="--input") && idx+1 < argc)
    //     {
    //         src = fs::path(argv[++idx]);
    //         VANE_ASSERT(fs::exists(src), "Invalid path \"%s\"", src.c_str());

    //         if (fs::is_directory(src))
    //             readc_directory(PA, src);
    //         else
    //             readc_file(PA, src);
    //     }

    //     else if ((arg=="-o" || arg=="--output") && idx+1 < argc)
    //     {
    //         dst = std::string(argv[++idx]);
    //     }
    // }

    // PA.save(dst);
}


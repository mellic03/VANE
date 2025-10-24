#include <vane/core/assert.hpp>
#include <vane/util/file.hpp>
#include <vane/vfs/archive.hpp>
#include <filesystem>
namespace fs = std::filesystem;

static void readc_file(vane::PkgArchive&, std::filesystem::path);
static void readc_directory(vane::PkgArchive&, std::filesystem::path);

static std::vector<std::string> argvec;
static fs::path inpath;
static fs::path outpath;
static bool verbose;
static bool listmode;


bool check_args( int argc, char **argv )
{
    argvec.resize(argc-1);
    inpath   = fs::path("./");
    outpath  = fs::path("archive.pkg");
    verbose  = false;
    listmode = false;

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

        if (A=="-i" || A=="--input")
        {
            inpath = fs::path(argvec[++i]);
        }

        else if (A=="-o" || A=="--output")
        {
            outpath = fs::path(argvec[++i]);
        }

        else if (A=="-v" || A=="--verbose")
        {
            verbose = true;
        }

        else if (A=="-l" || A=="--list")
        {
            inpath = fs::path(argvec[++i]);
            listmode = true;
        }
    
        else
        {
            return false;
        }
    }

    return true;
}


int main( int argc, char **argv )
{
    if (!check_args(argc, argv))
    {
        printf(
            "Usage: vpkg [OPTION]... [FILE]...\n"
            "  -i --input    specify input file or directory.\n"
            "  -o --output   specify output file.\n"
            "  -v --verbose  print a message for each archived file.\n"
            "  -l --list     list archive contents.\n"
        );
        return 1;
    }

    vane::PkgArchive PA;

    VANE_ASSERT(fs::exists(inpath), "Invalid path \"%s\"", inpath.c_str());

    if (listmode == true)
    {
        PA.load(inpath.string());
        PA.for_each([](const vane::PkgArchive::FileHandle &F) {
            printf("%s\n", F.name.c_str());
        });
        return 0;
    }


    if (fs::is_directory(inpath))
        readc_directory(PA, inpath);
    else
        readc_file(PA, inpath);
    PA.save(outpath.string());

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



static void readc_file( vane::PkgArchive &PA, std::filesystem::path path )
{
    namespace fs = std::filesystem;
    auto name = path.string();
    auto data = vane::loadRaw(name);
    PA.add(name, &data[0], data.size());
}


#include <iostream>

static void readc_directory( vane::PkgArchive &PA, std::filesystem::path path )
{
    namespace fs = std::filesystem;

    for (const auto &entry: fs::directory_iterator(path))
    {
        if (!entry.is_directory()) continue;
        if (verbose) std::cout << entry.path().string() << "\n";
        readc_directory(PA, entry.path());
    }
    
    for (const auto &entry: fs::directory_iterator(path))
    {
        if (entry.is_directory()) continue;
        if (verbose) std::cout << entry.path().string() << "\n";
        readc_file(PA, entry.path());
    }
}

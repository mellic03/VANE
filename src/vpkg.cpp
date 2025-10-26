#include <vane/core/assert.hpp>
#include <vane/util/file.hpp>
#include <vane/vfs/archive.hpp>

#include <SDL3/SDL.h>
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

    VANE_ASSERT(fs::exists(inpath), "Invalid path \"%s\"", inpath.c_str());


    vane::PkgArchive PA;

    if (listmode == true)
    {
        PA.load(inpath.string());
        PA.for_each([](const vane::PkgArchive::FileHandle &F) {
            printf("%s\n", F.name);
        });
        return 0;
    }

    if (fs::is_directory(inpath))
        readc_directory(PA, inpath);
    else
        readc_file(PA, inpath);
    PA.save(outpath.string());

    return 0;

}



static void readc_file( vane::PkgArchive &PA, std::filesystem::path path )
{
    namespace fs = std::filesystem;
    auto name = fs::relative(path, inpath);
    auto data = vane::loadRaw(path.string());
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

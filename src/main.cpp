#include <vane/vane.hpp>
#include <vane/core/assert.hpp>
#include <vane/core/log.hpp>
#include <vane/gfx/gfx.hpp>
#include <vane/vec.hpp>

using namespace vane;

#include <vane/vfs/archive.hpp>
#include <vane/vfs/filesystem.hpp>
static vanefs::PkgFsReader vnFS("vdata.pkg");


#include <filesystem>
namespace fs = std::filesystem;



#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

bool DoTheImportThing( const std::string &pFile )
{
    // if (pFile[0]) {  } return true;

    // Create an instance of the Importer class
    Assimp::Importer importer;

    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll
    // probably to request more postprocessing than we do in this example.
    const aiScene* scene = importer.ReadFile( pFile,
        aiProcess_CalcTangentSpace       |
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);

    // If the import failed, report it
    if (nullptr == scene)
    {
        printf("Import error: %s\n", importer.GetErrorString());
        return false;
    }

    syslog log("DoTheImportThing");

    log("mNumAnimations: %lu", scene->mNumAnimations);
    log("mNumLights: %lu", scene->mNumLights);
    log("mNumMeshes: %lu", scene->mNumMeshes);
    log("mNumMaterials: %lu", scene->mNumMaterials);
    log("mNumSkeletons: %lu", scene->mNumSkeletons);
    log("mNumTextures: %lu", scene->mNumTextures);

    // printf(scene.)
    // Now we can access the file's contents.
    // DoTheSceneProcessing( scene);

    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}






#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
using json = nlohmann::json;


static void json_services( json &data )
{
    for (auto &[key, val]: data.items())
    {
        std::cout << key << ": " << val << "\n";
    }
}

static void json_test()
{
    // auto [base, size, zzz] = vnFS.open("init.json");
    auto *fh = vnFS.open("init.json");
    if (!fh)
    {
        return;
    }

    auto *base = (char*)vnFS.base(fh);
    json data = json::parse(base, base+vnFS.size(fh));
    for (auto &[key, val]: data.items())
    {
        if (key == "services")
        {
            json_services(val);
        }
    }
}


VaneService *loadService( VaneApp*, const char* );

int main( int argc, char **argv )
{
    auto base = fs::path(SDL_GetBasePath());
    // std::cout << base << "\n";
    fs::current_path(base); // / fs::path("../"));
    std::cout << fs::current_path() << "\n";

    // std::string cmd = "export LD_LIBRARY_PATH=" + std::string(SDL_GetBasePath());
    // std::system(cmd.c_str());
    json_test();

    DoTheImportThing("engine/model/unit-sphere.gltf");


    Platform platform;
    VaneApp *V = new VaneApp(platform);

    V->addService<GfxService>();

    // for (auto &entry: fs::recursive_directory_iterator(fs::path("./bin/srv/")))
    // {
    //     if (entry.is_directory())
    //         continue;

    //     if (auto *srv = loadService(V, entry.path().string().c_str()))
    //     {
    //         V->addService(srv);
    //         printf("loaded service \"%s\"\n", entry.path().string().c_str());
    //     }
    // }

    vane::AppEnter(*V, argc, argv);

    return 0;
}



VaneService *loadService( VaneApp *V, const char *filepath )
{
    fs::path inpath(filepath);
    VANE_ASSERT(fs::exists(inpath), "No such file \"%s\"", inpath.c_str());

    auto *obj = SDL_LoadObject(inpath.string().c_str());
    if (obj == NULL)
    {
        printf("A: %s\n", SDL_GetError());
        return nullptr;
    }

    auto *func = SDL_LoadFunction(obj, "GetInstance");
    if (func == NULL)
    {
        printf("B: %s\n", SDL_GetError());
        return nullptr;
    }

    using getfn_t = void* (*)(void*);
    return (VaneService*)((getfn_t)func)(V);
}

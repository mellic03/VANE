#include <vane/vane.hpp>
#include <vane/core/assert.hpp>
#include <vane/core/log.hpp>
#include <vane/gfx/gfx.hpp>
#include <vane/vec.hpp>
using namespace vane;

#include <filesystem>
namespace fs = std::filesystem;

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
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
    std::ifstream f("engine/init.json");
    json data = json::parse(f);

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
    fs::current_path(base / fs::path("../"));
    std::cout << fs::current_path() << "\n";
    // std::string cmd = "export LD_LIBRARY_PATH=" + std::string(SDL_GetBasePath());
    // std::system(cmd.c_str());

    // json_test();


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

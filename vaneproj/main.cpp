#include "game.hpp"
// #include <tobiaslocker/base64.hpp>

using namespace vane;



#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
using json = nlohmann::json;



// static void setup_ftab()
// {
//     #define LAZY_LMAO(Tp) [](VaneApp &V) { return static_cast<VaneService*>(new Tp(V)); }

//     using fptr_t = VaneService* (*)(VaneApp&);
//     std::unordered_map<std::string, fptr_t> ftab;
//     ftab["GfxService"]   = LAZY_LMAO(vane::GfxService);
//     ftab["AudioService"] = LAZY_LMAO(vane::GfxService);
//     ftab["FileService"]  = LAZY_LMAO(vane::GfxService);
//     ftab["NetService"]   = LAZY_LMAO(vane::GfxService);

//     #undef LAZY_LMAO
// }


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


int main( int argc, char **argv )
{
    namespace fs = std::filesystem;

    auto base = fs::path(SDL_GetBasePath());
    fs::current_path(base / fs::path("../"));

    printf("path: %s\n", std::filesystem::current_path().c_str());
    json_test();

    Platform platform;
    VaneApp V(platform);

    V.addService<GfxService>();
    V.addService<GameService>();

    vane::AppEnter(V, argc, argv);

    return 0;
}


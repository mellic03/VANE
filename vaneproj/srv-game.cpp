#include "game.hpp"

using namespace vane;


extern "C"
{
    void *GetInstance( void *V )
    {
        static GameService *srv = nullptr;
        if (!srv) srv = new GameService(*(VaneApp*)V);
        return (void*)srv;
    }
}


// #include <vane/core/abi.hpp>

// extern "C"
// {
//     void srv_startup( VaneABI *V )
//     {

//     }

//     void srv_shutdown( VaneABI *V )
//     {

//     }

//     void srv_preframe( VaneABI *V )
//     {

//     }

//     void srv_midframe( VaneABI *V )
//     {
//         if (V->keyPressed(SDL_SCANCODE_ESCAPE))
//         {
//             V->shutdown();
//         }
//     }

//     void srv_postframe( VaneABI *V )
//     {

//     }
// }

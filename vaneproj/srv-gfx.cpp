#include "game.hpp"

using namespace vane;


extern "C"
{
    void *GetInstance( void *V )
    {
        static GfxService *srv = nullptr;
        if (!srv) srv = new GfxService(*(VaneApp*)V);
        return (void*)srv;
    }
}


// #include <vane/core/abi.hpp>

// extern "C"
// {
//     void *GetInstance( void *V )
//     {
//         static GfxService *srv = nullptr;
//         if (!srv) srv = new GfxService(*(VaneApp*)V);
//         return (void*)srv;
//     }


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
//         ivec2 p = mPlat.mousePos();
//         gl::ClearColor(float(p.x)/512.0f, float(p.y)/512.0f, 0.0f, 1.0f);
//         gl::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         SDL_GL_SwapWindow(mPlat.mainWindow()->mWinSDL);
//     }

// }

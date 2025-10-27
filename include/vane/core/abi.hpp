#pragma once

#include <stddef.h>
#include <stdint.h>
// #include <vane/SDL.hpp>


// extern "C"
// {
//     struct VaneABI
//     {
//         void (*update)();
//         void (*preUpdate)();
//         void (*postUpdate)();

//         void (*shutdown)();

//         size_t (*time)();
//         size_t (*dtime)();


//         enum Mouse_: int {
//             Mouse_NONE,
//             Mouse_LEFT,
//             Mouse_MID,
//             Mouse_RIGHT,
//             Mouse_EXTRA1,
//             Mouse_EXTRA2,
//             Mouse_NUM_BUTTONS
//         };

//         bool (*mousePressed)(Mouse_, int n);
//         bool (*mouseReleased)(Mouse_, int n);
//         bool (*mouseClicked)(Mouse_, int n);

//         bool (*keyPressed)(SDL_Scancode);
//         bool (*keyReleased)(SDL_Scancode);
//         bool (*keyTapped)(SDL_Scancode);
//     };

//     // void srv_startup( VaneABI *V );
//     // void srv_shutdown( VaneABI *V );
//     // void srv_preframe( VaneABI *V );
//     // void srv_midframe( VaneABI *V );
//     // void srv_postframe( VaneABI *V );
// }


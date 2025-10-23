#include <vane/platform/platform.hpp>
#include <vane/core/log.hpp>
#include <vane/SDL.h>

using namespace vane;


KeyboardIO::KeyboardIO()
:   mCurrDown(SDL_NUM_SCANCODES, false),
    mPrevDown(SDL_NUM_SCANCODES, false)
{

}

void KeyboardIO::update( const SDL_Event &e ) // ( int key, bool state )
{
    int idx = e.key.keysym.scancode;
    mPrevDown[idx] = mCurrDown[idx];
    mCurrDown[idx] = (e.key.state == SDL_PRESSED) ? true : false;
}

bool KeyboardIO::keyPressed( int i )
{
    return !mPrevDown[i] && mCurrDown[i];
}

bool KeyboardIO::keyReleased( int i )
{
    return mPrevDown[i] && !mCurrDown[i];
}

bool KeyboardIO::keyTapped( int i )
{
    return i & false;
}


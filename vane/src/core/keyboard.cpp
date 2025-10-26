#include <vane/core/platform.hpp>
#include <vane/core/log.hpp>

using namespace vane;


KeyboardIO::KeyboardIO()
:   mCurrDown(SDL_SCANCODE_COUNT, false),
    mPrevDown(SDL_SCANCODE_COUNT, false)
{

}

void KeyboardIO::update( const SDL_Event &e ) // ( int key, bool state )
{
    int idx = e.key.scancode;
    mPrevDown[idx] = mCurrDown[idx];
    mCurrDown[idx] = e.key.down;
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


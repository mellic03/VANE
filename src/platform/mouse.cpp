#include <vane/platform/platform.hpp>
#include <vane/core/log.hpp>
#include <SDL2/SDL.h>
#include <cstring>

using namespace vane;


MouseIO::MouseIO()
{
    memset(mCurrDown, 0, sizeof(mCurrDown));
    memset(mPrevDown, 0, sizeof(mPrevDown));
    memset(mClicks,   0, sizeof(mClicks));
}

void MouseIO::update( const SDL_Event &e )
{
    int idx = e.button.button;

    switch (e.type)
    {
        default:
            VANE_ASSERT(false, "Invalid type!");
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&mPos.x, &mPos.y);
            break;
        case SDL_MOUSEBUTTONDOWN:
            mPrevDown[idx] = mCurrDown[idx];
            mCurrDown[idx] = true;
            mClicks[idx] = e.button.clicks;
            break;
        case SDL_MOUSEBUTTONUP:
            mPrevDown[idx] = mCurrDown[idx];
            mCurrDown[idx] = false;
            mClicks[idx] = 0;
            break;
        case SDL_MOUSEWHEEL:
            mDWheel.x += e.wheel.mouseX;
            mDWheel.y += e.wheel.mouseY;
            break;
    }
}

ivec2 MouseIO::mousePos()
{
    return mPos;
}

ivec2 MouseIO::mouseDelta()
{
    return mDPos;
}

bool MouseIO::mousePressed( Button btn, int clicks )
{
    int i = int(btn);
    bool c = clicks>0 && clicks==mClicks[i];
    return c && !mPrevDown[i] && mCurrDown[i];
}

bool MouseIO::mouseReleased( Button btn, int clicks )
{
    int i = int(btn);
    bool c = clicks>0 && clicks==mClicks[i];
    return c && mPrevDown[i] && !mCurrDown[i];
}

bool MouseIO::mouseClicked( Button btn, int )
{
    int i = int(btn);
    return (!mPrevDown[i] && mCurrDown[i]) && false;
}



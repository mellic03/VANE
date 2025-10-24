#pragma once

#include <SDL2/SDL.h>
#include <vane/vec.hpp>
#include <set>
#include <string>
#include <vector>


namespace vane
{
    class NativeWindow;

    struct KeyboardIO_Data;
    class KeyboardIO;
    
    struct MouseIO_Data;
    class MouseIO;

    class Platform;
}


class vane::NativeWindow
{
public:
    SDL_Window *mWinSDL;
    void *mCtxGL;

private:
    friend class vane::Platform;
    vane::Platform &mPlatform;
    NativeWindow( Platform&, const std::string &title, int w=0, int h=0 );

};



class vane::KeyboardIO
{
public:
    KeyboardIO();
    void update( const SDL_Event& );
    bool keyPressed( int key );
    bool keyReleased( int key );
    bool keyTapped( int key );

private:
    std::vector<bool> mCurrDown;
    std::vector<bool> mPrevDown;
};



class vane::MouseIO
{
public:
    enum class Button: int {
        NONE, LEFT, MID, RIGHT, EXTRA1, EXTRA2, NUM_BUTTONS
    };

    MouseIO();
    void update( const SDL_Event& );
    ivec2 mousePos();
    ivec2 mouseDelta();
    bool mousePressed( Button, int clicks=0 );
    bool mouseReleased( Button, int clicks=0 );
    bool mouseClicked( Button, int n );

private:
    ivec2 mPos, mDPos, mDWheel;
    bool mCurrDown[int(Button::NUM_BUTTONS)];
    bool mPrevDown[int(Button::NUM_BUTTONS)];
    int  mClicks[int(Button::NUM_BUTTONS)];
};



class vane::Platform
:   public vane::KeyboardIO,
    public vane::MouseIO
{
public:
    Platform();

    void update();
    NativeWindow *mainWindow();
    NativeWindow *createWindow( const std::string &title, int w, int h );
    void destroyWindow( NativeWindow* );
    
private:
    NativeWindow            *mMainWin;
    std::set<NativeWindow*>  mWindows;
};


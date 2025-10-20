#pragma once


namespace vane
{
    class PixelImage;
}


class vane::PixelImage
{
public:
    static PixelImage load_bmp( const char* );
    static PixelImage load_png( const char* );
    static PixelImage load_jpg( const char* );

private:
    // SDL_Surface *mSurface;
    // int mW, mH, mPitch, mBPP;
    // SDL_ScaleMode mScaleMode = SDL_SCALEMODE_NEAREST;

};



// class EmuImageFont: public EmuImageBuffer
// {
// private:
//     // vec2 glyph_scale;

// public:
//     EmuImageFont( const std::string &filepath );
//     // ImageFont( void *p, int w, int h, int bpp, int pitch )
//     // :   mData((uint8_t*)p), mW(w), mH(h), mBpp(bpp), mPitch(pitch) {  };

//     ivec2 getGlyphExtents();
//     ivec2 getGlyphCorner( char ch );
// };


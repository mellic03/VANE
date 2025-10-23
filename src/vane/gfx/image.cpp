#include <vane/gfx/image.hpp>
#include <fstream>

using namespace vane;


PixelImage PixelImage::load_bmp( const char *path )
{
    std::ifstream stream(path, std::ifstream::binary);
    PixelImage img;

    return img;
}


// PixelImage PixelImage::load_png( const char *path )
// {

// }


// PixelImage PixelImage::load_jpg( const char *path )
// {

// }


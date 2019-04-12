#include <cstdlib>
#include "region.h"

Region::Region(Texture2D &texture, float sx, float sy, int width, int height) : texture(texture)
{
    rect.x = sx;
    rect.y = sy;
    rect.width = width;
    rect.height = height;
}

void Region::FlipX(bool value)
{
    if (value)
        rect.width = -abs(rect.width);
    else
        rect.width = abs(rect.width);
}

void Region::FlipY(bool value)
{
    if (value)
        rect.height = -abs(rect.height);
    else
        rect.height = abs(rect.height);
}



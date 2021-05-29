#include <cstdlib>
#include "region.h"

Region::Region(Texture2D &texture, float sx, float sy, int width, int height) : texture(texture)
{
	rect.x = sx;
	rect.y = sy;
	rect.width = float(width);
	rect.height = float(height);
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



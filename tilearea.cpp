#include "tilearea.h"

TileArea::TileArea(const string &regionName)
{
	region = Atlas::GetRegion(regionName);
}

TileArea::TileArea(Texture2D &texture)
{
	region = new Region(texture, 0, 0, texture.width, texture.height);
}

void TileArea::Init(Texture2D &texture)
{
	region = new Region(texture, 0, 0, texture.width, texture.height);
}

void TileArea::Draw(Vector2 position, int width, int height, Color tint)
{
	_sx = position.x;

	while(position.y < height)
	{
		while (position.x < width)
		{            
			DrawTextureRec(region->texture, region->rect, position, tint);        
			position.x += region->rect.width;
		}

		position.y += region->rect.height;
		position.x = _sx;
	}
}
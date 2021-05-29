#include "tileset.h"

Tileset::Tileset(const string &regionName, int tileWidth, int tileHeight)
{
	Init(regionName, tileWidth, tileHeight);
}

Tileset::Tileset(Texture2D &texture, int tileWidth, int tileHeight)
{
	Init(texture, tileWidth, tileHeight);
}

void Tileset::Init(const string &regionName, int tileWidth, int tileHeight)
{
	region = Atlas::GetRegion(regionName);
	Setup(tileWidth, tileHeight);
}

void Tileset::Init(Texture2D &texture, int tileWidth, int tileHeight)
{
	region = new Region(texture, 0, 0, texture.width, texture.height);
	Setup(tileWidth, tileHeight);
}

void Tileset::Setup(int tileWidth, int tileHeight)
{
	_rect.width = float(tileWidth);
	_rect.height = float(tileHeight);

	widthInTiles = int(region->rect.width / _rect.width);
	heightInTiles = int(region->rect.height / _rect.height);
}

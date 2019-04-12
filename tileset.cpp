#include "tileset.h"

Tileset::Tileset(const string &regionName, int tileWidth, int tileHeight)
{
    region = Atlas::GetRegion(regionName);
    Setup(tileWidth, tileHeight);
}

Tileset::Tileset(Texture2D &texture, int tileWidth, int tileHeight)
{
    region = new Region(texture, 0, 0, texture.width, texture.height);
    Setup(tileWidth, tileHeight);
}

void Tileset::Init(Texture2D &texture, int tileWidth, int tileHeight)
{
    region = new Region(texture, 0, 0, texture.width, texture.height);
    Setup(tileWidth, tileHeight);
}

void Tileset::Setup(int tileWidth, int tileHeight)
{
    //this->tileWidth = tileWidth;
    //this->tileHeight = tileHeight;

    _rect.width = tileWidth;
    _rect.height = tileHeight;

    widthInTiles = region->rect.width / _rect.width;
    heightInTiles = region->rect.height / _rect.height;
}

Tileset::~Tileset()
{
    //dtor
}

#ifndef TILESET_H
#define TILESET_H

#include <string>
#include "raylib.h"
#include "atlas.h"
#include "region.h"

class Tileset
{
	public:

		Region *region;
		int widthInTiles;
		int heightInTiles;

		Tileset(){};
		Tileset(const string &regionName, int tileWidth, int tileHeight);
		Tileset(Texture2D &texture, int tileWidth, int tileHeight);
		void Init(const string &regionName, int tileWidth, int tileHeight);
		void Init(Texture2D &texture, int tileWidth, int tileHeight);
		int GetTileWidth();
		int GetTileHeight();
		void Draw(int index, Vector2 &position, Color tint = WHITE);

	private:

		float _x;
		float _y;
		Rectangle _rect;

		void Setup(int tileWidth, int tileHeight);

};

inline int Tileset::GetTileWidth()
{
	return (int)_rect.width;
}

inline int Tileset::GetTileHeight()
{
	return (int)_rect.height;
}

inline void Tileset::Draw(int index, Vector2 &position, Color tint)
{
	_x = (float)(index % widthInTiles);
	_y = (float)(index / widthInTiles);

	_rect.x = region->rect.x + (_x * _rect.width);
	_rect.y = region->rect.y + (_y * _rect.height);

	DrawTextureRec(region->texture, _rect, position, tint);
}

#endif // TILESET_H

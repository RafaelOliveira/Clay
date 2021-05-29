#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include "raylib.h"
#include "tileset.h"

class Tilemap
{
	public:

		Tileset *tileset;		
		int columns;
		int rows;
		int **data;
		int width;
		int height;

		Tilemap(){};
		void Init(Tileset& tileset, int** data, int rows, int columns);
		int GetTileWidth();
		int GetTileHeight();
		void SetTile(int x, int y, int value);
		int GetTile(int x, int y);
		void ClearTile(int x, int y);
		bool CheckPositionInside(int px, int py);
		void LoadEmpty(int columns, int rows);
		void CopyFrom2DArray(int **array);
		static vector<Tilemap> CreateFromPyxelEdit(const string &fileName, Tileset& tileset);
		static vector<Tilemap> CreateFromPyxelEditString(const string& content, Tileset& tileset);
		void Draw(Vector2 &position, Color tint);
		void Draw(Vector2 &position, int tileX, int tileY, int widthInTiles, int heightInTiles, Color tint);
		void DrawInCamera(Vector2 &position, Camera2D &camera, Color tint = WHITE);

	private:
				
		int _startCol = 0;
		int _endCol = 0;
		int _startRow = 0;
		int _endRow = 0;
};

inline int Tilemap::GetTileWidth()
{
    return tileset->GetTileWidth();
}

inline int Tilemap::GetTileHeight()
{
    return tileset->GetTileHeight();
}

#endif // TILEMAP_H
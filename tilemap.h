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
		Tilemap(Tileset &tileset);
		void Init(Tileset &tileset);
		int GetTileWidth();
		int GetTileHeight();
		void SetTile(int x, int y, int value);
		int GetTile(int x, int y);
		void ClearTile(int x, int y);
		bool CheckPositionInside(int px, int py);
		void LoadEmpty(int columns, int rows);
		void LoadFrom2DArray(int **array, int rows, int columns);
		static vector<int**> GetLayersFromPyxelEdit(const string &fileName, int &rows, int &columns);
		void Draw(Vector2 &position, Color tint);
		void DrawInCamera(Vector2 &position, Camera2D &camera, Color tint = WHITE);

	private:
		
		Vector2 _pos;
		int _startCol;
		int _endCol;
		int _startRow;
		int _endRow;
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
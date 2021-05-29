#ifndef GRID_H
#define GRID_H

#include "tilemap.h"

class Grid
{
	public:

		int columns;
		int rows;
		bool** data;

		void Init(Tilemap *tilemap, int solidTiles[], int arraySize);
		void InitEmpty(int columns, int rows);
		void SetTile(int tx, int ty, bool solid = true);
		bool GetTile(int tx, int ty);
		void ClearTile(int tx, int ty);
		bool CheckValidTile(int tx, int ty);
		void SetArea(int tx, int ty, int width, int height, bool solid = true);
		void ClearArea(int tx, int ty, int width, int height);
};

inline void Grid::SetTile(int tx, int ty, bool solid)
{
	data[ty][tx] = solid;
}

inline bool Grid::GetTile(int tx, int ty)
{
	return data[ty][tx];
}

inline void Grid::ClearTile(int tx, int ty)
{
	data[ty][tx] = false;
}

inline void Grid::ClearArea(int tx, int ty, int width, int height)
{
	SetArea(tx, ty, width, height, false);
}

#endif

#include "grid.h"

void Grid::Init(Tilemap& tilemap, int solidTiles[], int arraySize)
{
	data = new bool* [tilemap.rows];

	for (int y = 0; y < tilemap.rows; ++y)
	{
		data[y] = new bool[tilemap.columns];

		for (int x = 0; x < tilemap.columns; ++x)
		{
			int id = tilemap.GetTile(x, y);
			data[y][x] = false;
			
			for (int i = 0; i < arraySize; i++)
			{
				if (solidTiles[i] == id)
				{
					data[y][x] = true;
					break;
				}
			}
		}
	}
}

void Grid::InitEmpty(int columns, int rows)
{
	data = new bool* [rows];

	for (int y = 0; y < rows; ++y)
	{
		data[y] = new bool[columns];

		for (int x = 0; x < columns; ++x)
			data[y][x] = false;
	}
}

bool Grid::CheckValidTile(int tx, int ty)
{
	if (tx < 0 || tx > columns - 1 || ty < 0 || ty > rows - 1)
		return false;
	else
		return true;
}

void Grid::SetArea(int tx, int ty, int width, int height, bool solid)
{
	for (int yy = ty; yy < (ty + height); yy++)
	{
		for (int xx = tx; xx < (tx + width); tx++)
			SetTile(xx, yy, solid);
	}
}
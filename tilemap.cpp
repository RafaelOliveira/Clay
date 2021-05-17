#include <fstream>
#include <iostream>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <cmath>
#include "engine.h"
#include "tilemap.h"
#include "util.h"

Tilemap::Tilemap(Tileset &tileset)
{
	this->tileset = &tileset;
}

void Tilemap::Init(Tileset &tileset)
{
	this->tileset = &tileset;
}

void Tilemap::SetTile(int x, int y, int value)
{
	data[y][x] = value;
}

int Tilemap::GetTile(int x, int y)
{
	return data[y][x];
}

void Tilemap::ClearTile(int x, int y)
{
	SetTile(x, y, -1);
}

bool Tilemap::CheckPositionInside(int px, int py)
{
	if (px < 0 || px > columns - 1 || py < 0 || py > rows - 1)		
		return false;
	else		
		return true;
}

void Tilemap::LoadEmpty(int columns, int rows)
{
	this->rows = rows;
	this->columns = columns;

	height = rows * GetTileHeight();
	width = columns * GetTileWidth();

	data = new int*[rows];

	for (int y = 0; y < rows; ++y)
	{
		data[y] = new int[columns];

		for (int x = 0; x < columns; ++x)
			data[y][x] = -1;
	}
}

void Tilemap::LoadFrom2DArray(int **array, int rows, int columns)
{
	data = new int*[rows];

	for (int y = 0; y < rows; ++y)
	{
		data[y] = new int[columns];

		for (int x = 0; x < columns; ++x)
			data[y][x] = array[y][x];
	}

	this->rows = rows;
	this->columns = columns;

	height = rows * GetTileHeight();
	width = columns * GetTileWidth();
}

vector<int**> Tilemap::GetLayersFromPyxelEdit(const string &fileName, int &rows, int &columns)
{
	columns = 0;
	rows = 0;

	vector<int**> layers;
	vector<string> lines;
	int **layer;

	std::ifstream inf(fileName);

	if (!inf)
	{
		std::cerr << "(Tilemap.CreateFromPyxelEdit) file " + fileName + " not found";
		exit(1);
	}
	else
	{
		while (inf)
		{
			string line;
		
			std::getline(inf, line);
			rtrim(line);

			lines.push_back(line);
		}

		for (size_t i = 0; i < lines.size(); i++)
		{
			if (lines[i].length() > 0)
			{
				vector<string> tokens = split(lines[i], ' ');

				if (tokens[0] == "tileswide")
					columns = std::stoi(tokens[1]);
				else if (tokens[0] == "tileshigh")
					rows = std::stoi(tokens[1]);
				else if (tokens[0] == "layer")
				{
					layer = new int*[rows];

					for (int y = 0; y < rows; ++y)
					{
						layer[y] = new int[columns];

						for (int x = 0; x < columns; ++x)
							layer[y][x] = -1;
					}

					int lineStart = i + 1;
					
					for (int py = lineStart; py < (lineStart + rows); ++py)
					{
						vector<string> data = split(lines[py], ',');

						for (int px = 0; px < columns; ++px)
							layer[py - lineStart][px] = std::stoi(data[px]);
					}
					
					layers.push_back(layer);
				}
			}
		}
	}
	
	return layers;
}

void Tilemap::Draw(Vector2 &position, Color tint)
{
	Vector2 _pos;

	for (int my = 0; my < rows; ++my)
	{
		for (int mx = 0; mx < columns; ++mx)
		{
			if (data[my][mx] != -1)
			{
				_pos.x = position.x + (mx * GetTileWidth());
				_pos.y = position.y + (my * GetTileHeight());
				tileset->Draw(data[my][mx], _pos, tint);
			}
		}
	}
}

void Tilemap::Draw(Vector2 &position, int tileX, int tileY, int tileColumns, int tileRows, Color tint)
{
	Vector2 _pos;
	int r = tileY + tileRows;
	int c = tileX + tileColumns;

	for (int my = tileY; my < r; ++my)
	{
		for (int mx = tileX; mx < c; ++mx)
		{
			if (data[my][mx] != -1)
			{
				_pos.x = position.x + (mx * GetTileWidth());
				_pos.y = position.y + (my * GetTileHeight());
				tileset->Draw(data[my][mx], _pos, tint);
			}
		}
	}
}

void Tilemap::DrawInCamera(Vector2 &position, Camera2D &camera, Color tint)
{
	if 	(((position.x + width) < camera.offset.x) || (position.x > (camera.offset.x + Engine::screenWidth)) ||
			((position.y + height) < camera.offset.y) || (position.y > (camera.offset.y + Engine::screenHeight)))
				return;

	_startCol = floor((position.x > camera.offset.x ? 0 : (camera.offset.x - position.x)) / GetTileWidth());
	_endCol = int(((position.x + width) > (camera.offset.x + Engine::screenWidth) ? (camera.offset.x + Engine::screenWidth - position.x) : width) / GetTileWidth());
	_startRow = floor((position.y > camera.offset.y ? 0 : (camera.offset.y - position.y)) / GetTileHeight());
	_endRow = int(((position.y + height) > (camera.offset.y + Engine::screenHeight) ? (camera.offset.y + Engine::screenHeight - position.y) : height) / GetTileHeight());

	if (_endCol < columns)
			_endCol++;
			
	if (_endRow < rows)
		_endRow++;

	int tile = 0;
	Vector2 _pos;
	
	for (int r = _startRow; r < _endRow; r++)
	{
		for (int c = _startCol; c < _endCol; c++)
		{
			tile = data[r][c];

			if (tile != -1)
			{
				_pos.x = position.x + (c * GetTileWidth());
				_pos.y = position.y + (r * GetTileHeight());
				
				tileset->Draw(tile, _pos, tint);
			}
		}
	}	
}
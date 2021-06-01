#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
#include "util.h"

#define MAP_OBJECT 0
#define MAP_TILEMAP 1

class MapLoader
{
	public:

		void LoadMap(const string& mapFileName);
		virtual void GetMapItem(int itemType, string name, vector<string>& props);
};

#endif
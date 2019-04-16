#ifndef ATLAS_H
#define ATLAS_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include "raylib.h"
#include "region.h"
#include "util.h"

using std::map;
using std::string;
using std::vector;

class Atlas
{
	public:

		static Region* GetRegion(const string &regionName);
		static vector<Region*> GetRegions(vector<string> &regionNames);
		static vector<Region*> GetRegionsByIndex(const string &regionName, int startIndex, int endIndex);
		static vector<Region> CreateRegionList(Region &region, int regionWidth, int regionHeight);
		static Region CreateRegion(Texture2D &texture);
		static Region CreateRegion(Texture2D &texture, float sx, float sy, int width, int height);
		static Region CreateRegion(Region &region, float sx, float sy, int width, int height);
		static Region CreateRegion(const string &regionName, float sx, float sy, int width, int height);
		static void SaveRegion(Region &region, const string &name);
		static void SaveRegionList(vector<Region> &regions, const string &baseName);
		static void RemoveRegion(const string &regionName);
		static void LoadSimpleAtlas(Texture2D &texture, const string &fileName);
		static map<string, Region> CreateRegionsFromSimpleAtlas(Texture2D &texture, string &fileName);

	private:

		static map<string, Region> cache;
};

inline Region Atlas::CreateRegion(Texture2D &texture)
{
	return Region(texture, 0, 0, texture.width, texture.height);
}

inline Region Atlas::CreateRegion(Texture2D &texture, float sx, float sy, int width, int height)
{
	return Region(texture, sx, sy, width, height);
}

inline Region Atlas::CreateRegion(Region &region, float sx, float sy, int width, int height)
{
	return Region(region.texture, region.rect.x + sx, region.rect.y + sy, width, height);
}

inline void Atlas::SaveRegion(Region &region, const string &name)
{
	cache.insert(std::make_pair(name, region));
}

inline void Atlas::RemoveRegion(const string &regionName)
{
	cache.erase(regionName);
}

#endif // ATLAS_H

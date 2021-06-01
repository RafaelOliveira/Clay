#include "atlas.h"

map<string, Region> Atlas::cache;

Region* Atlas::GetRegion(const string &regionName)
{
	auto it = cache.find(regionName);

	if (it != cache.end())
		return &it->second;
	else
	{
		throw std::out_of_range("(Atlas.GetRegion) region " + regionName + " not found");
	}
}

vector<Region*> Atlas::GetRegions(vector<string> &regionNames)
{
	vector<Region*> listRegions;
	map<string, Region>::iterator it;

	for (auto &name: regionNames)
	{
		it = cache.find(name);

		if (it != cache.end())
			listRegions.push_back(&it->second);
		else
			throw std::out_of_range("(Atlas.GetRegions) region " + name + " not found");
	}

	return listRegions;
}

vector<Region*> Atlas::GetRegionsByIndex(const string &regionName, int startIndex, int endIndex)
{
	vector<string> listRegionNames;
	endIndex++;

	for (int i = startIndex; i < endIndex; i++)
		listRegionNames.push_back(regionName + "-" + std::to_string(i));

	return Atlas::GetRegions(listRegionNames);
}

vector<Region> Atlas::CreateRegionList(Region &region, int regionWidth, int regionHeight)
{
	vector<Region> regionList;

	auto cols = int(region.rect.width / regionWidth);
	auto rows = int(region.rect.height / regionHeight);

	for (auto r = 0; r < rows; r++)
	{
		for (auto c = 0; c < cols; c++)
		{
			regionList.push_back(Region(region.texture, region.rect.x + (c * regionWidth), region.rect.y + (r * regionHeight),
				regionWidth, regionHeight));
		}
	}

	return regionList;
}

Region Atlas::CreateRegion(const string &regionName, float sx, float sy, int width, int height)
{
	auto region = GetRegion(regionName);

	return Region(region->texture, region->rect.x + sx, region->rect.y + sy, width, height);
}

void Atlas::SaveRegionList(vector<Region> &regions, const string &baseName)
{
	auto size = (int)regions.size() + 1;

	for (auto i = 1; i < size; i++)
		cache.insert(std::make_pair(baseName + "-" + std::to_string(i), regions[i - 1]));
}

void Atlas::LoadData(Texture2D &texture, const string &fileName)
{
	std::ifstream inf(fileName);

	if (!inf)
	{
		std::cerr << "(Atlas.LoadSimpleAtlas) file " + fileName + " not found";
		exit(1);
	}
	else
	{
		while (inf)
		{
			string line;

			std::getline(inf, line);

			if (line.length() > 0)
			{
				auto dataItem = split(line, ';');
				auto region = Region(texture, std::stof(dataItem[1]), std::stof(dataItem[2]), std::stoi(dataItem[3]), std::stoi(dataItem[4]));

				cache.insert(std::make_pair(dataItem[0], region));
			}
		}
	}
}

map<string, Region> Atlas::CreateRegionsFromSimpleAtlas(Texture2D &texture, string &fileName)
{
	std::ifstream inf(fileName);
	map<string, Region> regions;

	if (!inf)
	{
		std::cerr << "(Atlas.LoadSimpleAtlas) file " + fileName + " not found";
		exit(1);
	}
	else
	{
		while (inf)
		{
			string line;

			std::getline(inf, line);

			auto dataItem = split(line, ';');
			auto region = Region(texture, std::stof(dataItem[1]), std::stof(dataItem[2]), std::stoi(dataItem[3]), std::stoi(dataItem[4]));

			regions.insert(std::make_pair(dataItem[0], region));
		}
	}

	return regions;
}

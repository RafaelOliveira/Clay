#include "map_loader.h"

void MapLoader::LoadMap(const string& mapFileName)
{
	const char* mapFileNameStr = mapFileName.c_str();

	if (FileExists(mapFileNameStr))
	{
		string allText = string(LoadFileText(mapFileNameStr));
		vector<string> lines = split(allText, '\n');

		string name;
		vector<string> tokens;
		vector<string> subTokens;
		int itemType;

		for (int i = 0; i < lines.size(); i++)
		{
			tokens = split(lines[i], ' ');

			if (tokens[0].compare("map") != 0)
			{
				itemType = MAP_OBJECT;
				name = tokens[0];
				tokens.erase(tokens.begin());
			}
			else
			{
				itemType = MAP_TILEMAP;
				name = tokens[1];
				tokens.erase(tokens.begin(), tokens.begin() + 2);
			}

			GetMapItem(itemType, name, tokens);
		}
	}
	else
	{
		std::cerr << "(MapLoader::LoadMap) file " + mapFileName + " not found";
		exit(1);
	}
}

void MapLoader::GetMapItem(int itemType, string name, vector<string>& props) {}
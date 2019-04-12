#ifndef TILEAREA_H
#define TILEAREA_H

#include <string>
#include "raylib.h"
#include "atlas.h"
#include "region.h"

using std::string;

class TileArea
{
    public:

        Region *region;

        TileArea(){};
        TileArea(const string &regionName);
        TileArea(Texture2D &texture);
        void Init(Texture2D &texture);
        void Render(Vector2 position, int width, int height, Color tint);

    private:

        float _sx;
};

#endif
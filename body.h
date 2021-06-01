#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"
#include "object.h"
#include "grid.h"

class Body
{
	public:

		Vector2 pos;
		Rectangle hitbox;
		bool og = false;

		void SetHitbox(float x, float y, int width, int height);
		void CheckPlatformTileCollision(Grid *grid, Vector2 *velocity, int tileWidth, int tileHeight);
		void CheckFreeTileCollision(Grid& grid, Vector2& velocity, int tileWidth, int tileHeight);
};

#endif

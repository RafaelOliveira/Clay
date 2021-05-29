#ifndef REGION_H
#define REGION_H

#include "raylib.h"
#include "util.h"

class Region
{
	public:

		Texture2D texture;
		Rectangle rect;

		Region(Texture2D &texture, float sx, float sy, int width, int height);
		void FlipX(bool value = true);
		void FlipY(bool value = true);
		void Draw(Vector2 &position, Color tint = WHITE);
		void DrawScaled(Vector2 &position, Vector2 &scaling, Color tint = WHITE);

};

inline void Region::Draw(Vector2 &position, Color tint)
{
	DrawTextureRec(texture, rect, position, tint);
}

inline void Region::DrawScaled(Vector2 &position, Vector2 &scaling, Color tint)
{
	Rectangle dstScaling { position.x, position.y, scaling.x, scaling.y };

	DrawTexturePro(texture, rect, dstScaling, Util::posZero, 0, tint);
}

#endif // REGION_H

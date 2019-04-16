#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"

class Engine
{
	public:

		static int screenWidth;
		static int screenHeight;

		static void Init(int screenWidth, int screenHeight, const char *title);
		static void SetScaling(int fromWidth, int fromHeight);
		static void GameLoop();

	private:

		static bool useScaling;        
		static RenderTexture2D scalingTexture;
		static Rectangle srcScaling;
		static Rectangle dstScaling;
		static void DrawScalingTexture();
};

inline void Engine::DrawScalingTexture()
{
	// NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
	DrawTexturePro(scalingTexture.texture, srcScaling, dstScaling, (Vector2){ 0, 0 }, 0, WHITE);
}

#endif

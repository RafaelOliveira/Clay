#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"
#include "state.h"
#include "util.h"

/*#ifdef PHYSAC_IMPLEMENTATION
#include "physac.h"
#endif*/

class Engine
{
	public:

		static int screenWidth;
		static int screenHeight;

		static int gameWidth;
		static int gameHeight;

		static bool finishApp;

		static void Init(const char *title, int gameWidth, int gameHeight, int scaling = 1);
		static void SwitchFullscreen();
		static void GameLoop();

	private:

		static bool useScaling;
		static int scaling;
		static RenderTexture2D scalingTexture;
		static Rectangle srcScaling;
		static Rectangle dstScaling;
		static void SetScaling();
		static void SetDstScaling(int width, int height);
		static void DrawScalingTexture();
};

inline void Engine::DrawScalingTexture()
{
	// NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
	DrawTexturePro(scalingTexture.texture, srcScaling, dstScaling, Util::posZero, 0, WHITE);
}

#endif

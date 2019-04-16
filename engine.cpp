#include "engine.h"
#include "state.h"

int Engine::screenWidth = 800;
int Engine::screenHeight = 450;
bool Engine::useScaling = false;
RenderTexture2D Engine::scalingTexture;
Rectangle Engine::srcScaling { 0.0, 0.0, 0.0, 0.0 };
Rectangle Engine::dstScaling { 0.0, 0.0, 0.0, 0.0 };

void Engine::Init(int screenWidth, int screenHeight, const char *title)
{
	Engine::screenWidth = screenWidth;
	Engine::screenHeight = screenHeight;
	
	InitWindow(screenWidth, screenHeight, title);
	SetTargetFPS(60);
}

void Engine::SetScaling(int fromWidth, int fromHeight)
{
	useScaling = true;    
	scalingTexture = LoadRenderTexture(fromWidth, fromHeight);

	srcScaling.width = (int)fromWidth;
	srcScaling.height = (int)-fromHeight;
	dstScaling.width = (int)screenWidth;
	dstScaling.height = (int)screenHeight;
}

void Engine::GameLoop()
{
	// Detect window close button or ESC key
	while (!WindowShouldClose())
	{
		// Update
		State::active->Update();

		// Draw
		BeginDrawing();

		if (useScaling)
		{
			BeginTextureMode(scalingTexture);
			State::active->Draw();
			EndTextureMode();
			DrawScalingTexture();			
		}
		else
			State::active->Draw();
		
		EndDrawing();
	}

	// De-Initialization

	// Close window and OpenGL context
	CloseWindow();
}

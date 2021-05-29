#include "engine.h"

int Engine::screenWidth = 800;
int Engine::screenHeight = 450;
int Engine::gameWidth = 0;
int Engine::gameHeight = 0;

bool Engine::useScaling = false;
int Engine::scaling = 1;
RenderTexture2D Engine::scalingTexture;
Rectangle Engine::srcScaling { 0.0, 0.0, 0.0, 0.0 };
Rectangle Engine::dstScaling { 0.0, 0.0, 0.0, 0.0 };
bool Engine::finishApp = false;

void Engine::Init(const char *title, int gameWidth, int gameHeight, int scaling)
{
	Engine::gameWidth = gameWidth;
	Engine::gameHeight = gameHeight;

	Engine::scaling = scaling;

	Engine::screenWidth = gameWidth * scaling;
	Engine::screenHeight = gameHeight * scaling;
	
	InitWindow(screenWidth, screenHeight, title);

	/*#ifdef PHYSAC_IMPLEMENTATION
	InitPhysics();
	#endif*/

	SetTargetFPS(60);

	finishApp = false;

	if (scaling != 1)
		Engine::SetScaling();
}

void Engine::SetScaling()
{
	useScaling = true;    
	scalingTexture = LoadRenderTexture(Engine::gameWidth, Engine::gameHeight);

	srcScaling.width = float(Engine::gameWidth);
	srcScaling.height = -float(Engine::gameHeight);
	SetDstScaling(Engine::screenWidth, Engine::screenHeight);
}

void Engine::SetDstScaling(int width, int height)
{
	dstScaling.width = float(width);
	dstScaling.height = float(height);
}

void Engine::SwitchFullscreen()
{
	if (IsWindowFullscreen())
	{
		ToggleFullscreen();
		SetWindowSize(screenWidth, screenHeight);
		
		SetDstScaling(Engine::screenWidth, Engine::screenHeight);

		if (scaling != 1)
			useScaling = true;
		else
			useScaling = false;
	}
	else
	{
		int monitorWidth = GetMonitorWidth(0);
		int monitorHeight = GetMonitorHeight(0);

		SetDstScaling(monitorWidth, monitorHeight);

		SetWindowSize(monitorWidth, monitorHeight);
		ToggleFullscreen();
		useScaling = true;
	}
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

		if (finishApp)
			break;
	}

	// De-Initialization
	/*#ifdef PHYSAC_IMPLEMENTATION
	ClosePhysics();
	#endif*/

	// Close window and OpenGL context
	CloseWindow();
}

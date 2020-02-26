#include "Application.h"
#include <stdio.h>

Application::Application()
{
	Window = nullptr;
	ScreenSurface = nullptr;

	bQuit = false;
}

bool Application::Initialize()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf_s("SDL could not init! SDL_Error: %s", SDL_GetError());
		return false;
	}
	else
	{
		Window = SDL_CreateWindow("Great2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
		
		ScreenSurface = SDL_GetWindowSurface(Window);

		return true;
	}
}

void Application::Quit()
{
	bQuit = true;
}

void Application::Close()
{
	// ScreenSurface is freed by this function
	SDL_DestroyWindow(Window);
	Window = nullptr;
	ScreenSurface = nullptr;

	SDL_Quit();
}
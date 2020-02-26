#pragma once

#include <SDL.h>
#include <memory>

class Application
{
public:

	Application();

	bool Initialize();

	void Close();

	void Quit();

	bool IsRunning() const { return !bQuit; }

private:

	SDL_Window* Window;

	SDL_Surface* ScreenSurface;

	bool bQuit;
};


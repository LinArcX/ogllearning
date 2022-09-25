#ifndef USERINTERFACE_GRAPHICAL_OPENGL_WINDOW_SDL_H
#define USERINTERFACE_GRAPHICAL_OPENGL_WINDOW_SDL_H

#include "../../../Window.hpp"

#ifdef _WIN32 // note the underscore: without it, it's not msdn official!
// Windows (x64 and x86)
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_cpuinfo.h>
#include <SDL/SDL_video.h>
#include <SDL/SDL_assert.h>
#elif __linux__
#include <SDL.h>
#include <SDL_cpuinfo.h>
#include <SDL_video.h>
#include <SDL_assert.h>
#endif

namespace ogl::userInterface::graphical {
	class Sdl : public Window
	{
	public:
		//Sdl();
		//~Sdl();

		virtual void initialize() override;
		virtual void create() override;
		virtual void handleEvents() override;
		virtual void swapBuffers() override;
		virtual void pollEvents() override;
		virtual void releaseResources() override;

	private:
		SDL_Window* m_window = NULL;
		SDL_GLContext m_context = NULL;
	};
}
#endif

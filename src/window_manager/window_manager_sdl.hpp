#ifndef WINDOW_MANAGER_SDL_H
#define WINDOW_MANAGER_SDL_H
#include "window_manager.hpp"

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

class WindowManagerSDL : public IWindowManager
{
public:
	WindowManagerSDL();
	~WindowManagerSDL();

	virtual void init() override;
	virtual void create_window() override;
	virtual void handle_events() override;
	virtual void swap_buffers() override;
	virtual void poll_events() override;
	virtual void release_resources() override;

private:
	SDL_Window* m_window = NULL;
	SDL_GLContext m_gl_context = NULL;
};
#endif // WINDOW_MANAGER_SDL_H

#include "window_manager_sdl.hpp"

#include <iostream>
#include "../utility/logger.hpp"
#include "../utility/constants.hpp"

#include "../utility/helper.hpp"
#include "../state_manager/context.hpp"
#include "../state_manager/app_state_exit.hpp"
#include "../state_manager/app_state_running.hpp"

WindowManagerSDL::WindowManagerSDL()
{
	set_width(APm_width);
	set_height(APP_HEIGHT);
	set_app_name(APP_NAME);
}

WindowManagerSDL::~WindowManagerSDL()
{
	release_resources();
}

void WindowManagerSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Logger::instance()->fatal_error("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
}

void WindowManagerSDL::create_window()
{
	m_window = SDL_CreateWindow(get_app_name().c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		get_width(), get_height(), SDL_WINDOW_OPENGL);

	if (nullptr == m_window)
	{
		Logger::instance()->fatal_error("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	// Create a OpenGL context on SDL2
	if (NULL == (m_gl_context = SDL_GL_CreateContext(m_window)))
	{
		Logger::instance()->fatal_error("Failed to create OpenGL context: %s\n", SDL_GetError());
	}
	else
	{
		SDL_GL_MakeCurrent(m_window, m_gl_context);
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void WindowManagerSDL::handle_events()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			Context::instance()->setState(AppStateExit::instance());
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_q:
			case SDLK_ESCAPE:
				Context::instance()->setState(AppStateExit::instance());
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			std::cout
				<< "x: " << event.motion.x
				<< " ,y: " << event.motion.y
				<< std::endl;
			break;
		default:
			break;
		}
	}
}

void WindowManagerSDL::swap_buffers()
{
	SDL_GL_SwapWindow(m_window);
}

void WindowManagerSDL::poll_events()
{
}

void WindowManagerSDL::release_resources()
{
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	SDL_Quit();
}

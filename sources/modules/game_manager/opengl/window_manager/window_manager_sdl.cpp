#include "window_manager_sdl.hpp"

#include <iostream>
#include <string>

#include "../../../utility/type_utility.hpp"
#include "../../../config_manager/config_manager_pc.hpp"
#include "../../../config_manager/config_manager_provider.hpp"

#include "../../../state_manager/context.hpp"
#include "../../../state_manager/app_state_exit.hpp"
#include "../../../state_manager/app_state_running.hpp"

#include "../../../logger_manager/logger_manager_provider.hpp"

WindowManagerSDL::WindowManagerSDL() {}

WindowManagerSDL::~WindowManagerSDL()
{
	release_resources();
}

void WindowManagerSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("SDL could not initialize! SDL_Error: %s\n" /* + SDL_GetError() */);
	}
}

void WindowManagerSDL::create_window()
{
	m_window = SDL_CreateWindow(
		ogl::ConfigManagerProvider::getConfigManager()->getAppName().c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		ogl::ConfigManagerProvider::getConfigManager()->getAppWidth(),
		ogl::ConfigManagerProvider::getConfigManager()->getAppHeight(),
		SDL_WINDOW_OPENGL);

	if (nullptr == m_window)
	{
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("Window could not be created!SDL_Error: % s\n");
	}

	// Create a OpenGL context on SDL2
	if (NULL == (m_gl_context = SDL_GL_CreateContext(m_window)))
	{
		// , SDL_GetError()
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("Failed to create OpenGL context: %s\n");
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
			ogl::Context::instance()->setState(ogl::AppStateExit::instance());
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_q:
			case SDLK_ESCAPE:
				ogl::Context::instance()->setState(ogl::AppStateExit::instance());
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

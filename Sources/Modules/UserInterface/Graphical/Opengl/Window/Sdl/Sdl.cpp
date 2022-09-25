#include <iostream>
#include <string>

#include "Sdl.hpp"

#include "../../../../../Utility/Type.hpp"
#include "../../../../../Configurations/Pc.hpp"
#include "../../../../../Configurations/Provider.hpp"

#include "../../../../../State/Context.hpp"
#include "../../../../../State/Application/Exit.hpp"
#include "../../../../../State/Application/Running.hpp"

#include "../../../../../Logger/Provider.hpp"

using namespace ogl::state;

//Sdl::Sdl() {}

//ogl::userInterface::graphical::Sdl::~Sdl()
//{
//	releaseResources();
//}

void ogl::userInterface::graphical::Sdl::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		ogl::logger::Provider::logger()->fatal("SDL could not initialize! SDL_Error: %s\n" /* + SDL_GetError() */);

	}
}

void ogl::userInterface::graphical::Sdl::create()
{
	m_window = SDL_CreateWindow(
		configurations::Provider::provider()->applicationName().c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		configurations::Provider::provider()->applicationWidth(),
		configurations::Provider::provider()->applicationHeight(),
		SDL_WINDOW_OPENGL);

	if (nullptr == m_window)
	{
		ogl::logger::Provider::logger()->fatal("Window could not be created!SDL_Error: % s\n");
	}

	m_context = SDL_GL_CreateContext(m_window);
	if (NULL == m_context)
	{
		std::string sdl_error(SDL_GetError());
		ogl::logger::Provider::logger()->fatal("Failed to create OpenGL context: %s\n" + sdl_error);
	}
	else
	{
		SDL_GL_MakeCurrent(m_window, m_context);
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void ogl::userInterface::graphical::Sdl::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			Context::instance()->setState(application::Exit::instance());
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_q:
			case SDLK_ESCAPE:
				Context::instance()->setState(application::Exit::instance());
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

void ogl::userInterface::graphical::Sdl::swapBuffers()
{
	SDL_GL_SwapWindow(m_window);
}

void ogl::userInterface::graphical::Sdl::pollEvents()
{
}

void ogl::userInterface::graphical::Sdl::releaseResources()
{
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	SDL_Quit();
}

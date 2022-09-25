#include "GladSdl.hpp"

#include <iostream>
#include <glad/glad.h>
#include <SDL/SDL.h>
#include "../../../../../../Logger/Provider.hpp"

using namespace ogl::userInterface::graphical::opengl::extensionLoader::glad::sdl;

void Sdl::initialize()
{
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		ogl::logger::Provider::logger()->fatal("Failed to initialize GLAD!");
	}
}

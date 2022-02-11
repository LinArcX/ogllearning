#include "extension_loader_glad_sdl.hpp"

#include <iostream>
#include <glad/glad.h>
#include <SDL/SDL.h>
#include "../utility/logger.hpp"

void ExtensionLoaderGladSdl::init()
{
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		Logger::instance()->fatal_error("Failed to initialize GLAD!");
	}
}

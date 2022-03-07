#include "extension_loader_glad_sdl.hpp"

#include <iostream>
#include <glad/glad.h>
#include <SDL/SDL.h>
#include "../../../logger_manager/logger_manager_provider.hpp"

void ExtensionLoaderGladSdl::init()
{
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("Failed to initialize GLAD!");
	}
}

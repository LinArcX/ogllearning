#include "extension_loader_glew.hpp"

#include <GL/glew.h>
#include "../utility/logger.hpp"

void ExtensionLoaderGLEW::init()
{
	glewExperimental = GL_TRUE; //Ensure it get all pointers
	if (GLEW_OK != glewInit())
	{
		Logger::instance()->fatal_error("Failed to initializes GLEW!");
	}
}

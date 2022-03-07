#include "extension_loader_glew.hpp"

#include <GL/glew.h>
#include "../../../logger_manager/logger_manager_provider.hpp"

void ExtensionLoaderGLEW::init()
{
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
	{
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("Failed to initialize GLEW!");
	}
}

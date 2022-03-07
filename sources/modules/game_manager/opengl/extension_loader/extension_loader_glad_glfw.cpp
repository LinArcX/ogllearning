#include "extension_loader_glad_glfw.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../../logger_manager/logger_manager_provider.hpp"

void ExtensionLoaderGladGlfw::init()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("Failed to initialize GLAD!");
	}
}

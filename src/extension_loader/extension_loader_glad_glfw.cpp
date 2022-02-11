#include "extension_loader_glad_glfw.hpp"

#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "../utility/logger.hpp"

void ExtensionLoaderGladGlfw::init()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Logger::instance()->fatal_error("Failed to initialize GLAD!");
	}
}

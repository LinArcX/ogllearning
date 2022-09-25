#include "Glfw.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../../../../../Logger/Provider.hpp"

using namespace ogl::userInterface::graphical::opengl::extensionLoader::glad::glfw;

void Glfw::initialize()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ogl::logger::Provider::logger()->fatal("Failed to initialize GLAD!");
	}
}

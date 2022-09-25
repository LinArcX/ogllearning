#include "Glew.hpp"

#include <iostream>
#include <GL/glew.h>
#include "../../../../../Logger/Provider.hpp"

using namespace ogl::userInterface::graphical::opengl::extensionLoader::glew;

void Glew::initialize()
{
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
	{
		ogl::logger::Provider::logger()->fatal("Failed to initialize GLEW!");
	}
}

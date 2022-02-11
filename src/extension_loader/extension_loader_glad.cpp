#include "extension_loader_glad.hpp"

#include <glad/glad.h>
#include "../utility/constants.hpp"
#include <iostream>

#if USE_GLFW
#include "../window_manager/window_manager_glfw.hpp"
#elif USE_SDL
#include "../window_manager/window_manager_sdl.hpp"
#endif

#include "../utility/logger.hpp"

void ExtensionLoaderGLAD::init()
{
#if USE_GLFW
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Logger::instance()->fatal_error("Failed to initialize GLAD!");
	}
#elif USE_SDL
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		Logger::instance()->fatal_error("Failed to initialize GLAD!");
	}
#endif
	std::cout << "" << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "" << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "" << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "" << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

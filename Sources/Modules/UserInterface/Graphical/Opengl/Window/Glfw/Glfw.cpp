#include "Glfw.hpp"

#include <iostream>

#include "../../../../../Utility/Type.hpp"
#include "../../../../../Configurations/Pc.hpp"

#include "../../../../../State/Context.hpp"
#include "../../../../../State/Application/Exit.hpp"
#include "../../../../../State/Application/Running.hpp"

#include "../../../../../Logger/Provider.hpp"

using namespace ogl::state;
using namespace ogl::userInterface::graphical::opengl::window;

//Glfw::Glfw() {}

//Glfw::~Glfw() {}

void Glfw::initialize()
{
	glfwInit();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Glfw::create()
{
	m_window = glfwCreateWindow(width(), height(), name().c_str(), NULL, NULL);
	if (!m_window)
	{
		ogl::logger::Provider::logger()->fatal("Failed to create GLFW window!");
	}
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

void Glfw::handleEvents()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS
		|| glfwWindowShouldClose(m_window))
	{
		Context::instance()->setState(application::Exit::instance());
	}
}

void Glfw::releaseResources()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Glfw::swapBuffers()
{
	glfwSwapBuffers(m_window);
}

void Glfw::pollEvents()
{
	glfwPollEvents();
}

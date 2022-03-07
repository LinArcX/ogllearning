#include "window_manager_glfw.hpp"

#include <iostream>

#include "../../../utility/type_utility.hpp"
#include "../../../config_manager/config_manager_pc.hpp"

#include "../../../state_manager/context.hpp"
#include "../../../state_manager/app_state_exit.hpp"
#include "../../../state_manager/app_state_running.hpp"

#include "../../../logger_manager/logger_manager_provider.hpp"

WindowManagerGLFW::WindowManagerGLFW() {}

WindowManagerGLFW::~WindowManagerGLFW() {}

void WindowManagerGLFW::init()
{
	glfwInit();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void WindowManagerGLFW::create_window()
{
	m_window = glfwCreateWindow(get_width(), get_height(), get_app_name().c_str(), NULL, NULL);
	if (!m_window)
	{
		ogl::LoggerManagerProvider::getLoggerManager()->fatal("Failed to create GLFW window!");
	}
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

void WindowManagerGLFW::handle_events()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS
		|| glfwWindowShouldClose(m_window))
	{
		ogl::Context::instance()->setState(ogl::AppStateExit::instance());
	}
}

void WindowManagerGLFW::release_resources()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void WindowManagerGLFW::swap_buffers()
{
	glfwSwapBuffers(m_window);
}

void WindowManagerGLFW::poll_events()
{
	glfwPollEvents();
}

#include "window_manager_glfw.hpp"

#include <iostream>
#include "../utility/logger.hpp"
#include "../utility/constants.hpp"

#include "../utility/helper.hpp"
#include "../state_manager/context.hpp"
#include "../state_manager/app_state_exit.hpp"
#include "../state_manager/app_state_running.hpp"

WindowManagerGLFW::WindowManagerGLFW()
{
	set_width(APP_width);
	set_height(APP_HEIGHT);
	set_app_name(APP_NAME);
}

WindowManagerGLFW::~WindowManagerGLFW()
{}

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
		Logger::instance()->fatal_error("Failed to create GLFW windown");
	}
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

void WindowManagerGLFW::handle_events()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS
		|| glfwWindowShouldClose(m_window))
	{
		Context::instance()->setState(AppStateExit::instance());
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


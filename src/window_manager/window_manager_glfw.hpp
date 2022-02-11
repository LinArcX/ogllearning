#ifndef WINDOW_MANAGER_GLFW_H
#define WINDOW_MANAGER_GLFW_H

#include "window_manager.hpp"
#include "../utility/constants.hpp"

#if USE_GLAD == 1
#include <glad/glad.h>
#elif USE_GLEW == 1
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

class WindowManagerGLFW : public WindowManager
{
public:
	WindowManagerGLFW();
	~WindowManagerGLFW();

	virtual void init() override;
	virtual void create_window() override;
	virtual void handle_events() override;
	virtual void release_resources() override;
	virtual void swap_buffers() override;
	virtual void poll_events() override;

private:
	GLFWwindow* m_window = NULL;
};
#endif // WINDOW_MANAGER_GLFW_H

#ifndef USERINTERFACE_GRAPHICAL_OPENGL_WINDOW_GLFW_H
#define USERINTERFACE_GRAPHICAL_OPENGL_WINDOW_GLFW_H

#include "../../../Window.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace window {
					class Glfw : public Window
					{
					public:
						//Glfw();
						//virtual ~Glfw();
						virtual void initialize() override;
						virtual void create() override;
						virtual void handleEvents() override;
						virtual void releaseResources() override;
						virtual void swapBuffers() override;
						virtual void pollEvents() override;

					private:
						GLFWwindow* m_window = NULL;
					};
				}
			}
		}
	}
}
#endif

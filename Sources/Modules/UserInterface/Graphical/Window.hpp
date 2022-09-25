#ifndef USERINTERFACE_GRAPHICAL_WINDOW_H
#define USERINTERFACE_GRAPHICAL_WINDOW_H

#include <iostream>

namespace ogl::userInterface::graphical {
	class Window
	{
	public:
		//Window() { ; }
		virtual ~Window() { ; }

		virtual void initialize() = 0;
		virtual void create() = 0;
		virtual void handleEvents() = 0;
		virtual void swapBuffers() = 0;
		virtual void pollEvents() = 0;
		virtual void releaseResources() = 0;

		int width() const { return m_width; }
		int height() const { return m_height; }
		std::string name() const { return m_name; }

		void setWidth(int width) { m_width = width; }
		void setHeight(int heigth) { m_height = heigth; }
		void setName(std::string name) { m_name = name; }

	private:
		int m_width;
		int m_height;
		std::string m_name;
	};
}
#endif

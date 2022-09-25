#include "LifeCycle.hpp"

//#include "utility/logger.hpp"

#include "../../../Utility/Type.hpp"
#include "../../../State/Context.hpp"
#include "../../../State/Application/Exit.hpp"
#include "../../../State/Application/Running.hpp"

using namespace ogl::state;
using namespace ogl::utility;
using namespace ogl::userInterface::graphical::opengl;

LifeCycle::LifeCycle(std::shared_ptr<ExtensionLoader> extensionLoader,
	std::shared_ptr<Window> window)
{
	m_extension_loader = extensionLoader;
	m_window = window;
  Context::setState(application::Running::instance());
}

LifeCycle::~LifeCycle() {}

void LifeCycle::initialize()
{
	m_window->initialize();
	m_window->create();
	m_extension_loader->initialize();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	initializeShaders();

	m_sprite.initialize(-1.0f, -1.0f, 1.5f, 1.5f);
	print_version();
}

void LifeCycle::initializeShaders()
{
	m_color_program.compileShaders("color_shading_vertex.hlsl", "color_shading_fragment.hlsl");

	m_color_program.addAttribute("vertex_position");
	m_color_program.addAttribute("vertext_color");

	m_color_program.linkShaders();
}

void LifeCycle::draw()
{
	m_time += 0.001f;
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_color_program.use();

	GLint time_location = m_color_program.uniformLocation("time");
	glUniform1f(time_location, m_time);
	m_sprite.draw();

	m_color_program.unuse();
}

void LifeCycle::loop()
{
	while (Type::instance()->sameType<application::Running>(Context::instance()->state()))
	{
		m_window->handleEvents();
		draw();
		m_window->swapBuffers();
		m_window->pollEvents();
	}
}

void LifeCycle::print_version()
{
	std::cout << "" << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "" << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "" << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "" << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void LifeCycle::run()
{
	initialize();
	loop();
	m_window->releaseResources();
}

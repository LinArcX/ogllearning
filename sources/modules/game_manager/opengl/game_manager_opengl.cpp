#include "game_manager_opengl.hpp"

//#include "utility/logger.hpp"

#include "../../utility/type_utility.hpp"
#include "../../state_manager/context.hpp"
#include "../../state_manager/app_state_exit.hpp"
#include "../../state_manager/app_state_running.hpp"

GameManagerOpenGL::GameManagerOpenGL(std::shared_ptr<IExtensionLoader> extension_loader,
	std::shared_ptr<IWindowManager> window_manager)
{
	this->extension_loader = extension_loader;
	this->window_manager = window_manager;
  ogl::Context::setState(ogl::AppStateRunning::instance());
}

GameManagerOpenGL::~GameManagerOpenGL() {}

void GameManagerOpenGL::init()
{
	window_manager->init();
	window_manager->create_window();
	extension_loader->init();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	init_shaders();
	m_sprite.init(-1.0f, -1.0f, 1.5f, 1.5f);
	print_version();
}

void GameManagerOpenGL::init_shaders()
{
	m_color_program.compile_shaders("color_shading_vertex.hlsl", "color_shading_fragment.hlsl");

	m_color_program.add_attribute("vertex_position");
	m_color_program.add_attribute("vertext_color");

	m_color_program.link_shaders();
}

void GameManagerOpenGL::draw()
{
	m_time += 0.001f;
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_color_program.use();

	GLint time_location = m_color_program.get_uniform_location("time");
	glUniform1f(time_location, m_time);
	m_sprite.draw();

	m_color_program.unuse();
}

void GameManagerOpenGL::loop()
{
	while (ogl::TypeUtility::instance()->IsType<ogl::AppStateRunning>(ogl::Context::instance()->getState()))
	{
		window_manager->handle_events();
		draw();
		window_manager->swap_buffers();
		window_manager->poll_events();
	}
}

void GameManagerOpenGL::print_version()
{
	std::cout << "" << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "" << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "" << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "" << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void GameManagerOpenGL::run()
{
	init();
	loop();
	window_manager->release_resources();
}

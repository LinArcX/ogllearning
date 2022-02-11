#include "game.hpp"
#include "utility/logger.hpp"
#include "utility/helper.hpp"
#include "state_manager/context.hpp"
#include "state_manager/app_state_exit.hpp"
#include "state_manager/app_state_running.hpp"

Game::Game(IExtensionLoader& extension_loader, IWindowManager& window_manager)
{
	m_extension_loader = &extension_loader;
	m_window_manager = &window_manager;
	Context::instance()->setState(AppStateRunning::instance());
}

Game::~Game()
{}

void Game::init()
{
	m_window_manager->init();
	m_window_manager->create_window();
	m_extension_loader->init();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	init_shaders();
	m_sprite.init(-1.0f, -1.0f, 1.5f, 1.5f);
	print_version();
}

void Game::init_shaders()
{
	m_color_program.compile_shaders("color_shading_vertex.hlsl", "color_shading_fragment.hlsl");

	m_color_program.add_attribute("vertex_position");
	m_color_program.add_attribute("vertext_color");

	m_color_program.link_shaders();
}

void Game::draw()
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

void Game::loop()
{
	while (Helper::instance()->IsType<AppStateRunning>(Context::instance()->getState()))
	{
		m_window_manager->handle_events();
		draw();
		m_window_manager->swap_buffers();
		m_window_manager->poll_events();
	}
}

void Game::print_version()
{
	std::cout << "" << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "" << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "" << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "" << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void Game::run()
{
	init();
	loop();
	m_window_manager->release_resources();
}

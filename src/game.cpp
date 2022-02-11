#include "game.hpp"
#include "utility/logger.hpp"
#include "utility/helper.hpp"
#include "state_manager/context.hpp"
#include "state_manager/app_state_exit.hpp"
#include "state_manager/app_state_running.hpp"

#if USE_GLAD
#include "extension_loader/extension_loader_glad.hpp"
#elif USE_GLEW
#include "extension_loader/extension_loader_glew.hpp"
#endif

#if USE_GLFW
#include "window_manager/window_manager_glfw.hpp"
#elif USE_SDL
#include "window_manager/window_manager_sdl.hpp"
#endif

Game::Game()
{
#if USE_GLAD
	m_extension_loader = new ExtensionLoaderGLAD();
#elif USE_GLEW
	m_extension_loader = new ExtensionLoaderGLEW();
#endif

#if USE_GLFW
	m_window_manager = new WindowManagerGLFW();
#elif USE_SDL
	m_window_manager = new WindowManagerSDL();
#endif
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
}

void Game::init_shaders()
{
	m_color_program.compile_shaders("color_shading_vertex.hlsl",
		"color_shading_fragment.hlsl");

	m_color_program.add_attribute("vertex_position");
	m_color_program.add_attribute("vertext_color");

	m_color_program.link_shaders();
}

void Game::handle_events()
{
	m_window_manager->handle_events();
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

void Game::run()
{
	Context::instance()->setState(AppStateRunning::instance());
	init();
	loop();
	m_window_manager->release_resources();
}

#ifndef GAME_MANAGER_OPENGL_H
#define GAME_MANAGER_OPENGL_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <memory>

#include "../game_manager.hpp"

#include "extension_loader/extension_loader.hpp"
#include "window_manager/window_manager.hpp"

#include "shaders/glsl_program.hpp"
#include "ingredients/sprite.hpp"

class GameManagerOpenGL : public GameManager
{
public:
	GameManagerOpenGL(std::shared_ptr<IExtensionLoader> extension_loader,
		std::shared_ptr<IWindowManager> window_manager);
	~GameManagerOpenGL();

	void init();
	void draw();
	void loop();
	void run();

private:
	void init_shaders();
	void print_version();

private:
	float m_time = 0;
	Sprite m_sprite;
	GLSLProgram m_color_program;
	std::shared_ptr<IExtensionLoader> extension_loader;
	std::shared_ptr<IWindowManager> window_manager;
};
#endif

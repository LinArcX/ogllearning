#ifndef GAME_H
#define GAME_H
#include <string>
#include <stdio.h>
#include <iostream>
#include <memory>

#include "extension_loader/extension_loader.hpp"
#include "window_manager/window_manager.hpp"

#include "shaders/glsl_program.hpp"
#include "ingredients/sprite.hpp"

class Game
{
public:
	Game(IExtensionLoader& extension_loader, IWindowManager& window_manager);
	~Game();
	void run();

private:
	void init();
	void init_shaders();
	void draw();
	void loop();
	void print_version();

private:
	float m_time = 0;
	Sprite m_sprite;
	GLSLProgram m_color_program;
	IExtensionLoader* m_extension_loader = nullptr;
	IWindowManager* m_window_manager = nullptr;
};
#endif // GAME_H

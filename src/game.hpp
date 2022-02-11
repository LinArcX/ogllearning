#ifndef GAME_H
#define GAME_H
#include <string>
#include <stdio.h>
#include <iostream>

#include "extension_loader/extension_loader.hpp"
#include "window_manager/window_manager.hpp"

#include "shaders/glsl_program.hpp"
#include "ingredients/sprite.hpp"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void init();
	void init_shaders();
	void handle_events();
	void draw();
	void loop();

private:
	float m_time = 0;
	Sprite m_sprite;
	GLSLProgram m_color_program;
	WindowManager* m_window_manager = NULL;
	ExtensionLoader* m_extension_loader = NULL;
};
#endif // GAME_H

#ifndef INGREDIENTS_SPRITE_H
#define INGREDIENTS_SPRITE_H

#include "../utility/constants.hpp"

#if USE_GLAD == 1
	#include <glad/glad.h>
#elif USE_GLEW == 1
	#include <GL/glew.h>
#endif

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);
	void draw();

private:
	float m_x;
	float m_y;
	float m_width;
	float m_height;
	GLuint m_vbo_id;
};
#endif // INGREDIENTS_SPRITE_H

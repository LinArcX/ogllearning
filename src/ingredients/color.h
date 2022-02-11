#ifndef INGREDIENTS_COLOR_H
#define INGREDIENTS_COLOR_H

#include "../utility/constants.hpp"

#if USE_GLAD == 1
	#include <glad/glad.h>
#elif USE_GLEW = 1
	#include <GL/glew.h>
#endif

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};
#endif // INGREDIENTS_COLOR_H

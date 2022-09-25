#ifndef USERINTERFACE_GRAPHICAL_OPENGL_INGREDIENTS_SPRITE_H
#define USERINTERFACE_GRAPHICAL_OPENGL_INGREDIENTS_SPRITE_H

#include <glad/glad.h>

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace ingredients {
					class Sprite
					{
					public:
						Sprite();
						~Sprite();

						void initialize(float x, float y, float width, float height);
						void draw();

					private:
						float m_x;
						float m_y;
						float m_width;
						float m_height;
						GLuint m_vbo_id;
					};
				}
			}
		}
	}
}
#endif

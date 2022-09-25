#ifndef USERINTERFACE_GRAPHICAL_OPENGL_PROGRAM_GLSL_H
#define USERINTERFACE_GRAPHICAL_OPENGL_PROGRAM_GLSL_H

#include <string>
#include <glad/glad.h>

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace program {
					class Program
					{
					public:
						Program();
						~Program();

						void compileShaders(const std::string& vertex_shader_file_path, const std::string& fragment_shader_file_path);
						void linkShaders();

						void addAttribute(const std::string& attribute_name);
						void use();
						void unuse();
						GLint uniformLocation(const std::string& uniform_name);

					private:
						void compileShader(const std::string& shader_file_path, GLuint shader_id);

					private:
						GLuint m_program_id = 0;
						GLuint m_vertex_shader_id;
						GLuint m_fragment_shader_id;
						int m_number_of_attributes;
					};
				}
			}
		}
	}
}
#endif

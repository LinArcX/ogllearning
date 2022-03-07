#ifndef SHADERS_GLSL_PROGRAM_H
#define SHADERS_GLSL_PROGRAM_H

#include <string>
#include <glad/glad.h>

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void compile_shaders(const std::string& vertex_shader_file_path, const std::string& fragment_shader_file_path);
	void link_shaders();

	void add_attribute(const std::string& attribute_name);
	void use();
	void unuse();
	GLint get_uniform_location(const std::string& uniform_name);

private:
	void compile_shader(const std::string& shader_file_path, GLuint shader_id);

private:
	GLuint m_program_id = 0;
	GLuint m_vertex_shader_id;
	GLuint m_fragment_shader_id;
	int m_number_of_attributes;
};
#endif

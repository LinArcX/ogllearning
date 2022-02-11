#include "glsl_program.hpp"
#include "../utility/logger.hpp"

#include <fstream>
#include <vector>

GLSLProgram::GLSLProgram() : m_number_of_attributes(0), m_program_id(0),
m_vertex_shader_id(0), m_fragment_shader_id(0)
{
}

GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::compile_shaders(const std::string& vertex_shader_file_path, const std::string& fragment_shader_file_path)
{
	m_program_id = glCreateProgram();
	m_vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	if (!m_vertex_shader_id)
	{
		Logger::instance()->fatal_error("Can't create vertext_shader!");
	}

	m_fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	if (!m_fragment_shader_id)
	{
		Logger::instance()->fatal_error("Can't create fragment_shader!");
	}

	compile_shader(vertex_shader_file_path, m_vertex_shader_id);
	compile_shader(fragment_shader_file_path, m_fragment_shader_id);
}

GLint GLSLProgram::get_uniform_location(const std::string& uniform_name)
{
	GLint location = glGetUniformLocation(m_program_id, uniform_name.c_str());
	if (location == GL_INVALID_INDEX)
	{
		Logger::instance()->fatal_error("Uniform: ", uniform_name.c_str(), ", not found in shader!");
	}
	return location;
}

void GLSLProgram::compile_shader(const std::string& shader_file_path, GLuint shader_id)
{
	std::ifstream shader_file(shader_file_path);
	if (shader_file.fail())
	{
		Logger::instance()->fatal_error("Failed to open: ", shader_file_path);
	}

	std::string file_content = "";
	std::string line;

	while (std::getline(shader_file, line))
	{
		file_content += line + "\n";
	}

	shader_file.close();

	const char* contents_ptr = file_content.c_str();
	glShaderSource(shader_id, 1, &contents_ptr, nullptr);
	glCompileShader(shader_id);

	GLint success = 0;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

	if (GL_FALSE == success)
	{
		GLint max_lenght = 0;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &max_lenght);

		std::vector<char> error_log(max_lenght);
		glGetShaderInfoLog(shader_id, max_lenght, &max_lenght, &error_log[0]);
		glDeleteShader(shader_id);

		Logger::instance()->fatal_error("Failed to compile: ", shader_file_path, "!\n", &(error_log[0]));
	}
}

void GLSLProgram::link_shaders()
{
	// Attach our shaders to our program
	glAttachShader(m_program_id, m_vertex_shader_id);
	glAttachShader(m_program_id, m_fragment_shader_id);

	// Link our program
	glLinkProgram(m_program_id);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(m_program_id, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(m_program_id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<char> error_log(maxLength);
		glGetProgramInfoLog(m_program_id, maxLength, &maxLength, &error_log[0]);

		// We don't need the program anymore.
		glDeleteProgram(m_program_id);
		// Don't leak shaders either.
		glDeleteShader(m_vertex_shader_id);
		glDeleteShader(m_fragment_shader_id);
		// Use the infoLog as you see fit.
		Logger::instance()->fatal_error("Failed to link: !\n", &(error_log[0]));
	}

	glDetachShader(m_program_id, m_vertex_shader_id);
	glDetachShader(m_program_id, m_fragment_shader_id);

  glDeleteShader(m_vertex_shader_id);
  glDeleteShader(m_fragment_shader_id);
}

void GLSLProgram::add_attribute(const std::string& attribute_name)
{
	glBindAttribLocation(m_program_id, m_number_of_attributes++, attribute_name.c_str());
}

void GLSLProgram::use()
{
	glUseProgram(m_program_id);
	for (int i = 0; i < m_number_of_attributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void GLSLProgram::unuse()
{
	glUseProgram(0);
	for (int i = 0; i < m_number_of_attributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

#include <cstddef>
#include "sprite.hpp"
#include "vertex.hpp"

Sprite::Sprite() : m_x(0.0f), m_y(0.0f), m_width(0.0f), m_height(0.0f), m_vbo_id(0)
{}

Sprite::~Sprite()
{
	if (!m_vbo_id)
	{
		glDeleteBuffers(1, &m_vbo_id);
	}
}

void Sprite::init(float x, float y, float width, float height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;

	if (!m_vbo_id)
	{
		glGenBuffers(1, &m_vbo_id);
	}

	Vertex vertex_data[6];

	// first triangle
	vertex_data[0].position.x = x + width;
	vertex_data[0].position.y = y + height;

	vertex_data[1].position.x = x;
	vertex_data[1].position.y = y + height;

	vertex_data[2].position.x = x;
	vertex_data[2].position.y = y;

	// second triangle
	vertex_data[3].position.x = x;
	vertex_data[3].position.y = y;

	vertex_data[4].position.x = x + width;
	vertex_data[4].position.y = y;

	vertex_data[5].position.x = x + width;
	vertex_data[5].position.y = y + height;

	for (int i = 0; i < 6; i++)
	{
		vertex_data[i].color.r = 255;
		vertex_data[i].color.g = 0;
		vertex_data[i].color.b = 255;
		vertex_data[i].color.a = 255;
	}

	vertex_data[1].color.r = 0;
	vertex_data[1].color.g = 0;
	vertex_data[1].color.b = 255;
	vertex_data[1].color.a = 255;

	vertex_data[4].color.r = 0;
	vertex_data[4].color.g = 255;
	vertex_data[4].color.b = 0;
	vertex_data[4].color.a = 255;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
	glEnableVertexAttribArray(0);

	// this is the position attribute pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	// this is the color attribute pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// The vertex shader operates on each vertext.
#version 130

// Input data from the VBO. Each vertex is 2 float(x, y)
in vec2 vertex_position;
in vec4 vertex_color;

out vec2 fragment_position;
out vec4 fragment_color;

void main()
{
  gl_Position.xy = vertex_position;
  gl_Position.z = 0.0;
  gl_Position.w = 1.0; // Indicates that the coordinates are normalized.

  fragment_color = vertex_color;
  fragment_position = vertex_position;
}
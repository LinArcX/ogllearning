// The fragment shader operates on each pixel in a given polygon.
#version 130

in vec2 fragment_position;
in vec4 fragment_color;
// This is the 3 component float vector that gets outputed to the screen for each pixel.
out vec4 color;

uniform float time;

void main()
{
	//color = fragment_color + vec4(1.0 * (cos(time) + 1.0) * 0.5,
	//															1.0 * (cos(time + 2.0) + 1.0) * 0.5,
	//															1.0 * (sin(time) + 1.0) * 0.5, 0.0);
	color = vec4(fragment_color.r * (cos(fragment_position.x + time) + 1.0) * 0.5,
		fragment_color.g * (cos(fragment_position.y + time) + 1.0) * 0.5,
		fragment_color.b * (cos(fragment_position.x * 0.4 + time) + 1.0) * 0.5, 1.0);

}
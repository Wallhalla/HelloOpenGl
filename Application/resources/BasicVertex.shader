#version 330 core

layout(location = 0) in vec2 position; // the position variable has attribute position 0

uniform mat4 ModelMatrix;

void main()
{
	gl_Position = ModelMatrx * vec4(position.x, position.y, 0.f, 1.0f);
}

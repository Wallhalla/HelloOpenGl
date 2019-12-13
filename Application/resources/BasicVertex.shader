#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 ModelMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 ViewMatrix;

void main()
{
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(position.x, position.y, 0.f, 1.0f);
}

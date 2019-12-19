#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec4 color;

out vec4 FragColor;
out vec3 FragNormal;
out vec3 FragSunLight;

uniform mat4 ModelMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 ViewMatrix;
uniform vec3 SunLight;

void main()
{
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(position.x, position.y, position.z, 1.0f);
	FragColor = color;

	FragNormal = (ModelMatrix * vec4(normal.x, normal.y, normal.z,  0.f)).xyz;
	FragSunLight = SunLight;
}

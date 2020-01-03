#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec3 normal;

out vec4 FragColor;
out vec3 FragNormal;

uniform mat4 ModelMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 ViewMatrix;

void main()
{
	// Calculate the Vertex Position.
	mat4 modelView = ViewMatrix * ModelMatrix;
	gl_Position = ProjectionMatrix * modelView * vec4(position.x, position.y, position.z, 1.0f);	

	// Calculate the Vertex Normal.
	mat4 normalMatrix = transpose(inverse(modelView));
	FragNormal = (normalMatrix * vec4(normal, 0.0)).xyz;

	// Pass the Color to the FragmentShader.
	FragColor = color;
}

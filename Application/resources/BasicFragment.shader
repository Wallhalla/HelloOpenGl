#version 330 core

layout(location = 0) out vec4 color;

in vec4 FragColor;
in vec3 FragNormal;

struct DirectionalLight
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec3 direction;
};

uniform DirectionalLight dirLight;

void main()
{
	// calc diffuse
	vec3 normal = normalize(FragNormal);
	vec3 light = normalize(dirLight.direction);
	
	float diffuseFactor = max(dot(normal, -light), 0.0f);
	vec4 diff = dirLight.diffuse; // *diffuseFactor;
	
	// calc specular

	color = diff * FragColor;
};
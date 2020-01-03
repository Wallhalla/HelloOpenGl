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
	// Set Ambient Light Input
	vec4 ambientLightInput = dirLight.ambient;

	// Calculate Diffuse Light Input
	vec3 normal = normalize(FragNormal);
	vec3 light = normalize(dirLight.direction) * -1;
	
	float diffuseFactor = max(dot(normal, light), 0.0f);
	vec4 diffuseLightInput = dirLight.diffuse * diffuseFactor;	
	
	// calc specular (Todo...)
	vec4 specularLightInput = vec4(0.0, 0.0, 0.0, 0.0);

	color = (ambientLightInput + diffuseLightInput + specularLightInput) * FragColor;
};
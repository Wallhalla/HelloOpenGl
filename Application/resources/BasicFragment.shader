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

	vec3 light = normalize(dirLight.direction) * 1;
	
	float diffuseFactor = max(dot(normal, light), 0.0f);
	vec4 diffuseLight = vec4(0.0, 0.0, 0.0, 1.0);

	if (diffuseFactor <= 0.0)
	{
		color = vec4(0.0, 0.0, 1.0, 1.0);		 
	}
	else
	{
		diffuseLight = vec4(diffuseLight.xyz * diffuseFactor, 1.0);
		color = (dirLight.ambient + diffuseLight) * FragColor;
	}
	
	// calc specular

	
};
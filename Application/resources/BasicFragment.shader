#version 330 core

layout(location = 0) out vec4 color;

uniform float AmbientLightIntensity;
uniform vec4 AmbientLightColor;


in vec4 FragColor;
in vec3 FragNormal;
in vec3 FragSunLight;

void main()
{
	vec4 ambient = AmbientLightIntensity * AmbientLightColor;
	vec3 normal = normalize(FragNormal);
	vec3 sunlight = normalize(-FragSunLight);

	float diffuse = max(dot(normal, sunlight), 0.0);
	vec4 diff = diffuse * vec4(1.f, 1.f, 1.f, 1.f);

	color = (ambient + diff) * FragColor;
};
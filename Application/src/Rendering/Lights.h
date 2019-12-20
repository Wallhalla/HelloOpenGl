#pragma once
#include "GLM/glm.hpp"

struct Light
{
public:
	glm::vec4 Ambient;
	glm::vec4 Diffuse;
	glm::vec4 Specular;
};

struct DirectionalLight : Light
{
public:
	glm::vec3 Direction;
};

struct PointLight : Light
{
public:
	glm::vec4 Position;
};



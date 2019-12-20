#pragma once
#include "GLM\glm.hpp"

struct Vertex
{
public:
	Vertex() {};
	Vertex(glm::vec3 position, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec3 normal = glm::vec3(0.f, 0.f, 0.f));

	glm::vec3 Position;	
	glm::vec4 Color;

};
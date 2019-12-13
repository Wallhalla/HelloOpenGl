#pragma once
#include "OpenGlVertexBuffer.h"
#include "Transform.h"

class Cube
{
public:
	Cube(const class ShaderProgram& shader);

	void Draw();
	Transform& GetTransform();

private:
	Transform m_transform;
	float* m_Data;
};
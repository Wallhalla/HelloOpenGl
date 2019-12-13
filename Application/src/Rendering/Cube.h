#pragma once
#include "OpenGlVertexBuffer.h"
#include "Transform.h"

class Cube
{
public:
	Cube(class ShaderProgram& shader);

	void Draw();
	Transform& GetTransform();

private:
	Transform m_transform;
	float* m_Data;
	unsigned int* m_Indices;

	unsigned int m_buffer;
	unsigned int m_ibo;

	class ShaderProgram& m_Shader;
};
#pragma once
#include "Transform.h"
#include "Vertex.h"
#include "Model.h"

class Cube : public Model
{
public:
	Cube();

	void Bind();
	void Unbind();
	void Draw(class ShaderProgram& shader);

private:
	Vertex m_Vertices[8];
	
	unsigned int m_buffer;
	unsigned int m_ibo;	
};
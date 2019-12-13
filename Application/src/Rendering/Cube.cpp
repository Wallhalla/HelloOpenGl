#include "Cube.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "ShaderProgram.h"

Cube::Cube(ShaderProgram& shader)
	:m_Shader(shader)
{
	m_Data = new float[8 * 3]
	{
		-1.f, -1.f, -1.f,	// Links unten vorne
		1.f, -1.f, -1.f,	// Rechts unten vorne
		-1.f, 1.f, -1.f,	// Links oben vorne 
		1.f, 1.f, -1.f,		// Rechts oben vorne 

		-1.f, -1.f, 1.f,	// Links unten hinten
		1.f, -1.f, 1.f,	// Rechts unten hinten
		-1.f, 1.f, 1.f,	// Links oben hinten 
		1.f, 1.f, 1.f,		// Rechts oben hinten 
	};

	m_buffer;
	glGenBuffers(1, &m_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
	glBufferData(GL_ARRAY_BUFFER, 8*3*sizeof(float), m_Data, GL_STATIC_DRAW);

	m_Indices = new unsigned int[36]
	{
		0, 1, 2, 1, 3, 2,  // Front-Face
		5, 4, 6, 5, 6, 7,   // Back-Face
		2, 3, 7, 2, 7, 6,	// Top-Face
		4, 5, 1, 4, 1, 0,	// Back-Face
		4, 0, 2, 4, 2, 6,	// Left-Face
		1, 5, 7, 1, 7, 3,	// Right-Face
	};

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_ibo);	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(unsigned int), m_Indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cube::Draw()
{
	m_Shader.Bind();
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,      // mode
		6,					// count
		GL_UNSIGNED_INT,   // type
		(void*)0           // element array buffer offset
	);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Transform& Cube::GetTransform()
{
	return m_transform;
}

#include "Cube.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "ShaderProgram.h"

static unsigned int s_Indices[36]
{
	// front
	0, 1, 2,
	2, 3, 0,
	// right
	1, 5, 6,
	6, 2, 1,
	// back
	7, 6, 5,
	5, 4, 7,
	// left
	4, 0, 3,
	3, 7, 4,
	// bottom
	4, 5, 1,
	1, 0, 4,
	// top
	3, 2, 6,
	6, 7, 3
};

static GLfloat s_Vertices[]
{
	// front
	-1.0, -1.0,  1.0,
	1.0, -1.0,  1.0,
	1.0,  1.0,  1.0,
	-1.0,  1.0,  1.0,
	// back
	-1.0, -1.0, -1.0,
	1.0, -1.0, -1.0,
	1.0,  1.0, -1.0,
	-1.0,  1.0, -1.0
};

Cube::Cube()	
{
	//m_Vertices[0] = Vertex({ -1.0f, -1.0f, 1.0f });// Links unten vorne
	//m_Vertices[1] = Vertex({ 1.0f, -1.0f, 1.0f });// Rechts unten vorne
	//m_Vertices[2] = Vertex({ -1.0f, 1.0f, 1.0f });// Links oben vorne
	//m_Vertices[3] = Vertex({ 1.0f, 1.0f, 1.0f });// Rechts oben vorne 
	//m_Vertices[4] = Vertex({ -1.0f, -1.0f, -1.0f }); // Links unten hinten
	//m_Vertices[5] = Vertex({ 1.0f, -1.0f, -1.0f });// Rechts unten hinten
	//m_Vertices[6] = Vertex({ -1.0f, 1.0f, -1.0f });// Links oben hinten
	//m_Vertices[7] = Vertex({ 1.0f, 1.0f, -1.0f });// Rechts oben hinten
	
	m_buffer;
	glGenBuffers(1, &m_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_Vertices), s_Vertices, GL_STATIC_DRAW);	

	glGenBuffers(1, &m_ibo);	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_Indices), s_Indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Cube::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
}

void Cube::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cube::Draw(ShaderProgram& shader)
{
	Bind();
	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,								// mode
		sizeof(s_Indices) / sizeof(unsigned int),	// count
		GL_UNSIGNED_INT,							// type
		(void*)0									// element array buffer offset
	);	
	Unbind();
}
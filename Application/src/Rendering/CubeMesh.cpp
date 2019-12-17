#include "CubeMesh.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "Vertex.h"

bool CubeMesh::m_IsLoaded = false;
unsigned int CubeMesh::m_Vbo = 0;
unsigned int CubeMesh::m_Ibo = 0;

const static unsigned int s_Indices[36]
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

static Vertex s_Vertices[]
{
	// front
	Vertex(glm::vec3(-1.0, -1.0,  1.0)),
	Vertex(glm::vec3(1.0, -1.0,  1.0)),
	Vertex(glm::vec3(1.0,  1.0,  1.0)),
	Vertex(glm::vec3(-1.0,  1.0,  1.0)),
	// back
	Vertex(glm::vec3(-1.0, -1.0, -1.0)),
	Vertex(glm::vec3(1.0, -1.0, -1.0)),
	Vertex(glm::vec3(1.0,  1.0, -1.0)),
	Vertex(glm::vec3(-1.0,  1.0, -1.0))
};

void CubeMesh::Load()
{
	m_Vbo;
	glGenBuffers(1, &m_Vbo);

	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_Vertices), s_Vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &m_Ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_Indices), s_Indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	m_IsLoaded = true;
}

CubeMesh::CubeMesh()
{
	if (!m_IsLoaded)
	{
		Load();
	}
}

void CubeMesh::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
}

void CubeMesh::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void CubeMesh::Draw() const
{
	Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (const void*) offsetof(Vertex, Position));

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,								// mode
		sizeof(s_Indices) / sizeof(unsigned int),	// count
		GL_UNSIGNED_INT,							// type
		(void*)0									// element array buffer offset
	);
	Unbind();
}

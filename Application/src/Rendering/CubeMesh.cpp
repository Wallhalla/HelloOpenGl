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

	// back
	4, 5, 6,
	6, 7, 4,

	// left
	8, 9, 10,
	10, 11, 8,

	// right
	12, 13, 14,
	14, 15, 12,
	
	// top
	16, 17, 18,
	18, 19, 16,

	// bottom
	20, 21, 22,
	22, 23, 20
	
};

static glm::vec4 Red(1.f, 0.f, 0.f, 1.f);
static glm::vec4 Green(0.f, 1.f, 0.f, 1.f);
static glm::vec4 Blue(0.f, 0.f, 1.f, 1.f);
static glm::vec4 Grey(0.3f, 0.3f, 0.3f, 1.f);
static glm::vec4 White(1.f, 1.f, 1.f, 1.f);
static glm::vec4 Yellow(1.f, 1.f, 0.f, 1.f);
static glm::vec4 Black(0.f, 0.f, 0.f, 1.f);

static Vertex s_Vertices[]
{
	// front
	Vertex(glm::vec3(-1.0, -1.0,  1.0), Red),	// 0 links unten vorne
	Vertex(glm::vec3(1.0, -1.0,  1.0), Red),	// 1 rechts unten vorne
	Vertex(glm::vec3(1.0,  1.0,  1.0), Red),	// 2 rechts oben vorne
	Vertex(glm::vec3(-1.0,  1.0,  1.0), Red),	// 3 links oben vorne
	// back
	Vertex(glm::vec3(-1.0, -1.0, -1.0), Green),	// 4 links unten hinten
	Vertex(glm::vec3(1.0, -1.0, -1.0), Green),	// 5 rechts unten hinten
	Vertex(glm::vec3(1.0,  1.0, -1.0), Green),	// 6 rechts oben hinten
	Vertex(glm::vec3(-1.0,  1.0, -1.0), Green),	// 7 links oben hinten
	// left
	Vertex(glm::vec3(-1.0, -1.0, -1.0), Blue),	// 8 links unten hinten
	Vertex(glm::vec3(-1.0, -1.0, 1.0), Blue),	// 9 links unten vorne
	Vertex(glm::vec3(-1.0,  1.0, 1.0), Blue),	// 10 links oben vorne
	Vertex(glm::vec3(-1.0,  1.0, -1.0), Blue),	// 11 links oben hinten
	// right
	Vertex(glm::vec3(1.0, -1.0, 1.0), Grey),		// 12 rechts unten vorne
	Vertex(glm::vec3(1.0, -1.0, -1.0), Grey),		// 13 rechts unten hinten
	Vertex(glm::vec3(1.0,  1.0, -1.0), Grey),		// 14 rechts oben hinten
	Vertex(glm::vec3(1.0,  1.0, 1.0), Grey),		// 15 rechts oben vorne
	// top
	Vertex(glm::vec3(-1.0, 1.0, 1.0), Yellow),		// 16 links oben vorne
	Vertex(glm::vec3(1.0, 1.0, 1.0), Yellow),		// 17 rechts oben vorne
	Vertex(glm::vec3(1.0,  1.0, -1.0), Yellow),		// 18 rechts oben hinten
	Vertex(glm::vec3(-1.0,  1.0, -1.0), Yellow),	// 19 links oben hinten
	// bottom
	Vertex(glm::vec3(-1.0, -1.0, -1.0), White),		// 20 links unten hinten
	Vertex(glm::vec3(1.0, -1.0, -1.0), White),		// 21 rechts unten hinten
	Vertex(glm::vec3(1.0,  -1.0, 1.0), White),		// 22 rechts unten vorne
	Vertex(glm::vec3(-1.0,  -1.0, 1.0), White)		// 23 links unten vorne
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*) offsetof(Vertex, Position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Color));

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,								// mode
		sizeof(s_Indices) / sizeof(unsigned int),	// count
		GL_UNSIGNED_INT,							// type
		(void*)0									// element array buffer offset
	);

	Unbind();
}

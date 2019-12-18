#include "CubeMesh.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "Vertex.h"
#include "Colors.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"

bool IsLoaded = false;

void CubeMesh::Load()
{
	m_Vao = new VertexArrayObject();
	m_Vbo = new VertexBufferObject();
	m_Ibo = new ElementBufferObject();

	Vertex vertices[24]
	{
		// front
		Vertex(glm::vec3(-1.0, -1.0,  1.0), Color::Red),		// 0 links unten vorne
		Vertex(glm::vec3(1.0, -1.0,  1.0),	Color::Red),		// 1 rechts unten vorne
		Vertex(glm::vec3(1.0,  1.0,  1.0),	Color::Red),		// 2 rechts oben vorne
		Vertex(glm::vec3(-1.0,  1.0,  1.0), Color::Red),		// 3 links oben vorne
		// back
		Vertex(glm::vec3(-1.0, -1.0, -1.0), Color::Green),		// 4 links unten hinten
		Vertex(glm::vec3(1.0, -1.0, -1.0),	Color::Green),		// 5 rechts unten hinten
		Vertex(glm::vec3(1.0,  1.0, -1.0),	Color::Green),		// 6 rechts oben hinten
		Vertex(glm::vec3(-1.0,  1.0, -1.0), Color::Green),		// 7 links oben hinten
		// left
		Vertex(glm::vec3(-1.0, -1.0, -1.0), Color::Blue),		// 8 links unten hinten
		Vertex(glm::vec3(-1.0, -1.0, 1.0),	Color::Blue),		// 9 links unten vorne
		Vertex(glm::vec3(-1.0,  1.0, 1.0),	Color::Blue),		// 10 links oben vorne
		Vertex(glm::vec3(-1.0,  1.0, -1.0), Color::Blue),		// 11 links oben hinten
		// right
		Vertex(glm::vec3(1.0, -1.0, 1.0),	Color::Grey),		// 12 rechts unten vorne
		Vertex(glm::vec3(1.0, -1.0, -1.0),	Color::Grey),		// 13 rechts unten hinten
		Vertex(glm::vec3(1.0,  1.0, -1.0),	Color::Grey),		// 14 rechts oben hinten
		Vertex(glm::vec3(1.0,  1.0, 1.0),	Color::Grey),		// 15 rechts oben vorne
		// top
		Vertex(glm::vec3(-1.0, 1.0, 1.0),	Color::Yellow),		// 16 links oben vorne
		Vertex(glm::vec3(1.0, 1.0, 1.0),	Color::Yellow),		// 17 rechts oben vorne
		Vertex(glm::vec3(1.0,  1.0, -1.0),	Color::Yellow),		// 18 rechts oben hinten
		Vertex(glm::vec3(-1.0,  1.0, -1.0), Color::Yellow),		// 19 links oben hinten
		// bottom
		Vertex(glm::vec3(-1.0, -1.0, -1.0), Color::White),		// 20 links unten hinten
		Vertex(glm::vec3(1.0, -1.0, -1.0),	Color::White),		// 21 rechts unten hinten
		Vertex(glm::vec3(1.0,  -1.0, 1.0),	Color::White),		// 22 rechts unten vorne
		Vertex(glm::vec3(-1.0,  -1.0, 1.0), Color::White)		// 23 links unten vorne
	};

	const unsigned int indices[36]
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

	m_Vao->Bind();
	
	m_Vbo->Bind();
	m_Vbo->BufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	m_Vao->SetupAttribPointers();
	m_Vbo->Unbind();

	m_Ibo->Bind();
	m_Ibo->BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	m_Ibo->Unbind();
	
	m_Vao->Unbind();
	IsLoaded = true;
}

void CubeMesh::Unload()
{
	delete m_Vbo;
	delete m_Ibo;
	IsLoaded = false;
}

CubeMesh::CubeMesh()
{
	if (!IsLoaded)
	{
		Load();
	}
}

void CubeMesh::Bind() const
{
	m_Vao->Bind();
	m_Vbo->Bind();
	m_Ibo->Bind();
}

void CubeMesh::Unbind() const
{
	m_Vao->Unbind();
	m_Vbo->Unbind();
	m_Ibo->Unbind();
}

void CubeMesh::Draw() const
{
	Bind();	

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,				// mode
		m_Ibo->GetIndicesCount(),	// count
		GL_UNSIGNED_INT,			// type
		(void*)0					// element array buffer offset
	);

	Unbind();
}

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

	glm::vec3 frontNormal = glm::vec3(0.f, 0.f, 1.f);
	glm::vec3 backNormal = glm::vec3(0.f, 0.f, -1.f);
	glm::vec3 leftNormal = glm::vec3(-1.f, 0.f, 0.f);
	glm::vec3 rightNormal = glm::vec3(1.f, 0.f, 0.f);
	glm::vec3 topNormal = glm::vec3(0.f, 1.f, 0.f);
	glm::vec3 bottomNormal = glm::vec3(0.f, -1.f, 0.f);

	Vertex vertices[24]
	{
		// front
		Vertex(glm::vec3(-1.0, -1.0,  1.0), Color::Red, frontNormal),		// 0 links unten vorne
		Vertex(glm::vec3(1.0, -1.0,  1.0),	Color::Red, frontNormal),		// 1 rechts unten vorne
		Vertex(glm::vec3(1.0,  1.0,  1.0),	Color::Red, frontNormal),		// 2 rechts oben vorne
		Vertex(glm::vec3(-1.0,  1.0,  1.0), Color::Red, frontNormal),		// 3 links oben vorne
		// back
		Vertex(glm::vec3(-1.0, -1.0, -1.0), Color::Green, backNormal),		// 4 links unten hinten
		Vertex(glm::vec3(1.0, -1.0, -1.0),	Color::Green, backNormal),		// 5 rechts unten hinten
		Vertex(glm::vec3(1.0,  1.0, -1.0),	Color::Green, backNormal),		// 6 rechts oben hinten
		Vertex(glm::vec3(-1.0,  1.0, -1.0), Color::Green, backNormal),		// 7 links oben hinten
		// left
		Vertex(glm::vec3(-1.0, -1.0, -1.0), Color::Blue, leftNormal),		// 8 links unten hinten
		Vertex(glm::vec3(-1.0, -1.0, 1.0),	Color::Blue, leftNormal),		// 9 links unten vorne
		Vertex(glm::vec3(-1.0,  1.0, 1.0),	Color::Blue, leftNormal),		// 10 links oben vorne
		Vertex(glm::vec3(-1.0,  1.0, -1.0), Color::Blue, leftNormal),		// 11 links oben hinten
		// right
		Vertex(glm::vec3(1.0, -1.0, 1.0),	Color::Grey, rightNormal),		// 12 rechts unten vorne
		Vertex(glm::vec3(1.0, -1.0, -1.0),	Color::Grey, rightNormal),		// 13 rechts unten hinten
		Vertex(glm::vec3(1.0,  1.0, -1.0),	Color::Grey, rightNormal),		// 14 rechts oben hinten
		Vertex(glm::vec3(1.0,  1.0, 1.0),	Color::Grey, rightNormal),		// 15 rechts oben vorne
		// top
		Vertex(glm::vec3(-1.0, 1.0, 1.0),	Color::Yellow, topNormal),		// 16 links oben vorne
		Vertex(glm::vec3(1.0, 1.0, 1.0),	Color::Yellow, topNormal),		// 17 rechts oben vorne
		Vertex(glm::vec3(1.0,  1.0, -1.0),	Color::Yellow, topNormal),		// 18 rechts oben hinten
		Vertex(glm::vec3(-1.0,  1.0, -1.0), Color::Yellow, topNormal),		// 19 links oben hinten
		// bottom
		Vertex(glm::vec3(-1.0, -1.0, -1.0), Color::White, bottomNormal),		// 20 links unten hinten
		Vertex(glm::vec3(1.0, -1.0, -1.0),	Color::White, bottomNormal),		// 21 rechts unten hinten
		Vertex(glm::vec3(1.0,  -1.0, 1.0),	Color::White, bottomNormal),		// 22 rechts unten vorne
		Vertex(glm::vec3(-1.0,  -1.0, 1.0), Color::White, bottomNormal)		// 23 links unten vorne
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

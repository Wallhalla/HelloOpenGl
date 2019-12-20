#include "VertexArrayObject.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &m_vao);
}

VertexArrayObject::~VertexArrayObject()
{
	glDeleteVertexArrays(1, &m_vao);
}

void VertexArrayObject::Bind() const
{
	glBindVertexArray(m_vao);
}

void VertexArrayObject::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArrayObject::SetupAttribPointers()
{
	glEnableVertexAttribArray(VertexAttributeLocation::Position);
	glEnableVertexAttribArray(VertexAttributeLocation::VertexColor);

	glVertexAttribPointer(VertexAttributeLocation::Position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Position));
	glVertexAttribPointer(VertexAttributeLocation::VertexColor, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Color));
}

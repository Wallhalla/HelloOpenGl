#include "VertexBufferObject.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

VertexBufferObject::VertexBufferObject()
{
	glGenBuffers(1, &m_vbo);	
}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, &m_vbo);
}

void VertexBufferObject::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void VertexBufferObject::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::BufferData(GLenum bufferType, GLsizeiptr bufferSize, const void * bufferData, GLenum drawMode)
{
	glBufferData(bufferType, bufferSize, bufferData, drawMode);
}

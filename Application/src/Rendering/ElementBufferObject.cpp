#include "ElementBufferObject.h"

ElementBufferObject::ElementBufferObject()
{
	glGenBuffers(1, &m_Ebo);
}

ElementBufferObject::~ElementBufferObject()
{
	glDeleteBuffers(1, &m_Ebo);
}

void ElementBufferObject::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);
}

void ElementBufferObject::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBufferObject::BufferData(GLenum bufferType, GLsizeiptr bufferSize, const void * bufferData, GLenum drawMode)
{
	glBufferData(bufferType, bufferSize, bufferData, drawMode);
	m_IndicesCount = bufferSize / sizeof(unsigned int);
}

unsigned int ElementBufferObject::GetIndicesCount() const
{
	return m_IndicesCount;
}

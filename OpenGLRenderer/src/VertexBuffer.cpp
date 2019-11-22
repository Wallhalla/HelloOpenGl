#include "OpenGLHeaders.h"
#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &_rendererId));
	Bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	Unbind();
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &_rendererId));
	int currentBuffer;
	glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &currentBuffer);
	ASSERT(currentBuffer != _rendererId);
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererId));
	int currentBuffer;
	glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &currentBuffer);
	ASSERT(currentBuffer == _rendererId);
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

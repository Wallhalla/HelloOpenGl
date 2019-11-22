#include "OpenGlVertexBuffer.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "Model.h"

OpenGlVertexBuffer::OpenGlVertexBuffer(const Model& model)
{
	m_BufferId;
	glGenBuffers(1, &m_BufferId);

	Bind();
	float* data = (float*)model.GetData();
	glBufferData(GL_ARRAY_BUFFER, model.GetSize(), data, GL_STATIC_DRAW);

	Unbind();
}

void OpenGlVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
}

void OpenGlVertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

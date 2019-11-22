#pragma once
#include "VertexBuffer.h"

class Model;

class OpenGlVertexBuffer : public VertexBuffer
{
public:
	OpenGlVertexBuffer(const Model& model);

	// Geerbt über VertexBuffer
	virtual void Bind() override;
	virtual void Unbind() override;

private:
	unsigned int m_BufferId;
};
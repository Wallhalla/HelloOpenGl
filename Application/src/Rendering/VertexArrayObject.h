#pragma once

class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();

	void Bind() const;
	void Unbind() const;

	void SetupAttribPointers();

private:
	unsigned int m_vao;
};
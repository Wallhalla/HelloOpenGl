#pragma once

enum VertexAttributeLocation
{
	Position = 0,
	VertexColor = 1,
	Normal = 2
};

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
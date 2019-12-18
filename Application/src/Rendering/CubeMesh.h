#pragma once
#include "Mesh.h"

class CubeMesh : public Mesh
{
public:
	CubeMesh();

public:
	virtual void Bind() const override;
	virtual void Unbind() const override;
	virtual void Draw() const override;

private:
	void Load();
	void Unload();	
	class VertexBufferObject* m_Vbo;
	class ElementBufferObject* m_Ibo;


};
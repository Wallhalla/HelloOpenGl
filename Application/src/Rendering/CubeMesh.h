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
	static bool m_IsLoaded;
	static unsigned int m_Vbo;
	static unsigned int m_Ibo;	
};
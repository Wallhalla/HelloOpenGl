#include "Cube.h"

Cube::Cube(const ShaderProgram& shader)
{
	m_Data = new float[8 * 3]
	{
		-1.f, -1.f, -1.f,	// Links unten vorne
		1.f, -1.f, -1.f,	// Rechts unten vorne
		-1.f, 1.f, -1.f,	// Links oben vorne 
		1.f, 1.f, -1.f,		// Rechts oben vorne 

		-1.f, -1.f, 1.f,	// Links unten hinten
		1.f, -1.f, 1.f,	// Rechts unten hinten
		-1.f, 1.f, 1.f,	// Links oben hinten 
		1.f, 1.f, 1.f,		// Rechts oben hinten 
	};
}

void Cube::Draw()
{
}

Transform& Cube::GetTransform()
{
	return m_transform;
}

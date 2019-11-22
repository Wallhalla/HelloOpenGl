#include "Model.h"

Model::Model()	
{
	m_Data = new float[3*3] {
		-0.5f, -0.5f, 0.0f, // links unten
		0.5f, -0.5f, 0.0f,	// rechts unten
		0.0f, 0.5f, 0.f	// Mitte oben
	};

	m_Size = 9 * sizeof(float);
}

unsigned int Model::GetSize() const
{
	return m_Size;
}

void* Model::GetData() const
{
	return m_Data;
}

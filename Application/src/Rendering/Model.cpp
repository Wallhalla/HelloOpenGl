#include "Model.h"

Model::Model()		
{
	m_Data = new float[4*3] {
		-1.0f, -1.0f, 0.0f, // links unten
		1.0f, -1.0f, 0.0f,	// rechts unten
		-1.0f, 1.0f, 0.f,	// links oben
		1.0f, 1.0f, 0.f		// rechts oben
	};

	m_Size = 12 * sizeof(float);
}

Model::~Model()
{
	delete m_Data;
}

unsigned int Model::GetSize() const
{
	return m_Size;
}

void* Model::GetData() const
{
	return m_Data;
}

Transform& Model::GetTransform()
{
	return m_transform;
}

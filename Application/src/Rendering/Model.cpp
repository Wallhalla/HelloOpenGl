#include "Model.h"

unsigned int Model::GetSize() const
{
	return 6 * sizeof(float);
}

void* Model::GetData() const
{
	float vertices[] = {
		-1.f, -1.f, // links unten
		1.f, -1.f,	// rechts unten
		0.f, 1.f	// Mitte oben
	};

	return vertices;
}

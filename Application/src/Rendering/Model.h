#pragma once
#include "Transform.h"

class Model
{
public:
	Model(const class Mesh& mesh);	
	~Model();	

	Transform& GetTransform();
	void Draw(const class ShaderProgram& shader);

private:
	Transform m_transform;
	const class Mesh& m_Mesh;
};

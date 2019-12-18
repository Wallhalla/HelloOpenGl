#include "Model.h"
#include "ShaderProgram.h"
#include "Mesh.h"

Model::Model(const Mesh & mesh)
	:m_Mesh(mesh)
{
}

Model::~Model()
{	
}

Transform& Model::GetTransform()
{
	return m_transform;
}

void Model::Draw(const ShaderProgram& shader)
{
	shader.Bind();	
	shader.SetModelMatrix(*this);
	m_Mesh.Draw();	
}

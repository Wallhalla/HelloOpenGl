#pragma once

#include <string>

class Model;

class ShaderProgram
{
public:
	ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

	void Bind();
	void Unbind();

	void SetModelMatrix(Model& model);

private:

	std::string ParseFile(const std::string& shaderfile);

	unsigned int m_ProgramId;	
};

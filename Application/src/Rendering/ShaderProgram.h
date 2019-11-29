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

	void Parse(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	void Compile();

	unsigned int m_ProgramId;
	unsigned int m_VertexShaderId;
	unsigned int m_FragmentShaderId;	
};

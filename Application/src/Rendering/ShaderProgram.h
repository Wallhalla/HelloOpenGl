#pragma once

#include <string>

class ShaderProgram
{
public:
	ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

	void Bind();
	void Unbind();

private:

	std::string ParseFile(const std::string& shaderfile);

	unsigned int m_ProgramId;	
};

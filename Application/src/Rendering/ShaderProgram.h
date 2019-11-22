#pragma once

#include <string>

class ShaderProgram
{
public:
	ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

	void Bind();
	void Unbind();

private:

	void Parse(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	void Compile();

	unsigned int m_ProgramId;
	unsigned int m_VertexShaderId;
	unsigned int m_FragmentShaderId;	
};

#include "ShaderProgram.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	m_ProgramId = glCreateProgram();

	Bind();
	Parse(vertexShaderFile, fragmentShaderFile);
	Compile();
	Unbind();
}

void ShaderProgram::Bind()
{
	glUseProgram(m_ProgramId);
}

void ShaderProgram::Unbind()
{
	glUseProgram(0);
}

void ShaderProgram::Parse(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	m_VertexShaderId = glCreateShader(GL_VERTEX_SHADER);

	const char* vsSrc = vertexShaderFile.c_str();
	glShaderSource(m_VertexShaderId, 1, &vsSrc, nullptr);
	glCompileShader(m_VertexShaderId);

	m_FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	const char* fsSrc = fragmentShaderFile.c_str();
	glShaderSource(m_FragmentShaderId, 1, &fsSrc, nullptr);
	glCompileShader(m_FragmentShaderId);	
}

void ShaderProgram::Compile()
{
	glAttachShader(m_ProgramId, m_VertexShaderId);
	glAttachShader(m_ProgramId,	m_FragmentShaderId);
	glLinkProgram(m_ProgramId);
	glValidateProgram(m_ProgramId);
}

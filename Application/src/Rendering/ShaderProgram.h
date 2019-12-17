#pragma once

#include <string>
#include "GLM/gtc/matrix_transform.hpp"

class Model;

class ShaderProgram
{
public:
	ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

	void Bind() const;
	void Unbind() const;

	void SetModelMatrix(Model& model) const;
	void SetProjectionMatrix(const glm::mat4& projection);
	void SetViewMatrix(const glm::mat4& viewMatrix);

public:

	std::string ParseFile(const std::string& shaderfile);

	unsigned int m_ProgramId;	
};

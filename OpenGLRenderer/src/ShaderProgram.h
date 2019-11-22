#pragma once
#include <string>
#include <unordered_map>
#include "gtc/matrix_transform.hpp"

class ShaderProgram
{
private:	

	struct ShaderProgramSource
	{
	public:
		std::string VertexSource;
		std::string FragmentSource;
		void Print();
	};

	unsigned int _id;
	std::string _filePath;

	ShaderProgramSource Parse(const std::string& filepath);
	unsigned int CreateShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);	
	unsigned int CompileShader(unsigned int type, const std::string& source);

	// uniform cache.
	std::unordered_map<std::string, int> _uniformLocationCache;

	int GetUniformLocation(const std::string& uniformName);

public:	
	ShaderProgram(const std::string& filePath);
	~ShaderProgram();

	void Bind() const;
	void Unbind() const;	
	void Delete();

	// Uniforms
	void SetUniform1i(const std::string& uniformName, int i);
	void SetUniform4f(const std::string& uniformName, float x, float y, float z, float a);
	void SetUniformMat4f(const std::string& uniformName, const glm::mat4& matrix);
	
};
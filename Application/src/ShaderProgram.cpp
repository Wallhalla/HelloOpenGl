#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "ShaderProgram.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ShaderProgram::ShaderProgramSource ShaderProgram::Parse(const std::string & filepath)
{	
	ifstream stream(filepath);

	enum class ShaderType : int
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	ShaderType type = ShaderType::NONE;

	string line;
	stringstream ss[2];

	while (getline(stream, line))
	{
		if (line.find("#shader") != string::npos)
		{
			if (line.find("vertex") != string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}

	return { ss[(int)ShaderType::VERTEX].str() , ss[(int)ShaderType::FRAGMENT].str() };
}

void ShaderProgram::ShaderProgramSource::Print()
{
	cout << "\nVertex Shader:" << endl;
	cout << VertexSource << endl;

	cout << "Fragment Shader:" << endl;
	cout << FragmentSource << endl;
}

ShaderProgram::ShaderProgram(const std::string & filePath)
	:_filePath(filePath)
{
	ShaderProgramSource source = Parse(filePath);
	_id = CreateShaderProgram(source.VertexSource, source.FragmentSource);
	source.Print();	
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(_id);
}

void ShaderProgram::Bind() const
{
	glUseProgram(_id);	
}

void ShaderProgram::Unbind() const
{
	glUseProgram(0);
}

void ShaderProgram::SetUniform1i(const std::string& uniformName, int i)
{
	glUniform1i(GetUniformLocation(uniformName), i);
}

void ShaderProgram::SetUniform4f(const std::string& uniformName, float x, float y, float z, float a)
{		
	glUniform4f(GetUniformLocation(uniformName), x, y, z, a);
}

void ShaderProgram::SetUniformMat4f(const std::string& uniformName, const glm::mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(uniformName), 1, GL_FALSE, &matrix[0][0]);
}

void ShaderProgram::Delete()
{
	glDeleteProgram(_id);
}

unsigned int ShaderProgram::CreateShaderProgram(const string& vertexShader, const string& fragmentShader)
{
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int ShaderProgram::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " Shader!" << endl;
		cout << message << endl;

		glDeleteShader(id);
		return 0;
	}

	return id;
}

int ShaderProgram::GetUniformLocation(const std::string& uniformName)
{
	if (_uniformLocationCache.find(uniformName) != _uniformLocationCache.end())
	{
		return _uniformLocationCache[uniformName]; 
	}

	int location = glGetUniformLocation(_id, uniformName.c_str());

	if (location == -1)
	{
		std::cout << "Warning: No Location found for: " << uniformName << std::endl;
		return location;
	}

	_uniformLocationCache[uniformName] = location;

	return location;
}

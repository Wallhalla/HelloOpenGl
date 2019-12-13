#include "ShaderProgram.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>      // std::ifstream
#include "Model.h"
#include "GLM/glm.hpp"

using namespace std;

ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
	// Read our shaders into the appropriate buffers
	std::string vertexSource = ParseFile(vertexShaderFile);
	std::string fragmentSource = ParseFile(fragmentShaderFile);

	// Create an empty vertex shader handle
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Send the vertex shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	const GLchar *source = (const GLchar *)vertexSource.c_str();
	glShaderSource(vertexShader, 1, &source, 0);

	// Compile the vertex shader
	glCompileShader(vertexShader);

	GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(vertexShader);

		// Use the infoLog as you see fit.
		std::cout << &infoLog[0] << std::endl;

		// In this simple program, we'll just leave
		return;
	}

	// Create an empty fragment shader handle
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Send the fragment shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	source = (const GLchar *)fragmentSource.c_str();
	glShaderSource(fragmentShader, 1, &source, 0);

	// Compile the fragment shader
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(fragmentShader);
		// Either of them. Don't leak shaders.
		glDeleteShader(vertexShader);

		// Use the infoLog as you see fit.
		std::cout << &infoLog[0] << std::endl;

		// In this simple program, we'll just leave
		return;
	}

	// Vertex and fragment shaders are successfully compiled.
	// Now time to link them together into a program.
	// Get a program object.
	m_ProgramId = glCreateProgram();

	// Attach our shaders to our program
	glAttachShader(m_ProgramId, vertexShader);
	glAttachShader(m_ProgramId, fragmentShader);

	// Link our program
	glLinkProgram(m_ProgramId);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(m_ProgramId, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(m_ProgramId, maxLength, &maxLength, &infoLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(m_ProgramId);
		// Don't leak shaders either.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		// Use the infoLog as you see fit.
		std::cout << &infoLog[0] << std::endl;

		// In this simple program, we'll just leave
		return;
	}

	// Always detach shaders after a successful link.
	glDetachShader(m_ProgramId, vertexShader);
	glDetachShader(m_ProgramId, fragmentShader);
}


void ShaderProgram::SetModelMatrix(Model& model)
{
	Transform& trans = model.GetTransform();
	GLint locationId = glGetUniformLocation(m_ProgramId, "ModelMatrix");

	glm::mat4 translation = glm::translate(glm::mat4(1.f), trans.GetTranslation());

	glm::vec3 rot = trans.GetRotation();
	glm::mat4 rotation = glm::mat4(1.f);

	if (rot.x != 0.f)
	{		
		rotation = glm::rotate(glm::mat4(1.f), glm::radians(rot.x), glm::vec3(1.f, 0.f, 0.0f));
	}

	if (rot.y != 0.f)
	{
		rotation = glm::rotate(glm::mat4(1.f), glm::radians(rot.y), glm::vec3(0.f, 1.f, 0.0f));
	}

	if (rot.z != 0.f)
	{
		rotation = glm::rotate(glm::mat4(1.f), glm::radians(rot.z), glm::vec3(0.f, 0.f, 1.0f));
	}

	glm::mat4 scale = glm::scale(glm::mat4(1.f), trans.GetScale());

	const glm::mat4 modelmatrix = translation * rotation * scale;

	glUniformMatrix4fv(locationId, 1, GL_FALSE, &modelmatrix[0][0]);
}

void ShaderProgram::SetProjectionMatrix(const glm::mat4& projection)
{	
	GLint locationId = glGetUniformLocation(m_ProgramId, "ProjectionMatrix");

	glUniformMatrix4fv(locationId, 1, GL_FALSE, &projection[0][0]);
}

void ShaderProgram::SetViewMatrix(const glm::mat4& viewMatrix)
{
	GLint locationId = glGetUniformLocation(m_ProgramId, "ViewMatrix");

	glUniformMatrix4fv(locationId, 1, GL_FALSE, &viewMatrix[0][0]);
}

string ShaderProgram::ParseFile(const std::string& shaderfile)
{
	ifstream stream(shaderfile);

	string line;
	stringstream ss;

	while (getline(stream, line))
	{
		ss << line << "\n";		
	}

	return ss.str();
}

void ShaderProgram::Bind()
{
	glUseProgram(m_ProgramId);
}

void ShaderProgram::Unbind()
{
	glUseProgram(0);
}
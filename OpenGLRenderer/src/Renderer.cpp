#include "OpenGLHeaders.h"
#include "Renderer.h"
#include <iostream>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

using namespace std;

void Renderer::GLClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Renderer::GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		cout
			<< "ERROR: Code=" << "0x" << std::hex << error <<
			"\nin Function: " << function <<
			"\nat Line: " << std::dec << line <<
			"\nin File: " << file << "\n" << endl;
		return false;
	}

	return true;
}

float Renderer::WindowWidth = 960.f;
float Renderer::WindowHeight = 540.f;

int Renderer::Init()
{
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	return 0;
}

unsigned int Renderer::CreateWindow()
{	
	/* Create a windowed mode window and its OpenGL context */
	_window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
	if (!_window)
	{
		glfwTerminate();
		return -1;
	}

	return 0;
}

void Renderer::CreateContext()
{
	/* Make the window's context current */
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1);

	GLenum error = glewInit() != GLEW_OK;

	if (error != GLEW_OK)
	{
		cout << "GLEW Error: " << glewGetErrorString(error) << endl;
	}

	cout << glGetString(GL_VERSION) << endl;

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(_window, true);
	ImGui_ImplOpenGL3_Init("#version 130");
	ImGui::StyleColorsDark();
}

bool Renderer::IsClosing()
{
	return glfwWindowShouldClose(_window);
}

void Renderer::Clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const ShaderProgram& shaderProgram) const
{
	/* Render here */
	shaderProgram.Bind();
	vao.Bind();
	ibo.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Swap()
{
	glfwSwapBuffers(_window);
}

void Renderer::Poll()
{
	glfwPollEvents();
}

void Renderer::Terminate()
{
	glfwTerminate();
}

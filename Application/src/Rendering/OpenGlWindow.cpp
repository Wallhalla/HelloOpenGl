#include "OpenGlWindow.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include "ShaderProgram.h"
#include "Vertex.h"
#include "Model.h"
#include "CubeMesh.h"

OpenGlWindow::OpenGlWindow(const std::string& title, unsigned int width, unsigned int height)
	:m_Title(title), m_Width(width), m_Height(height), m_Window(nullptr)
{
	/* Initialize the library */
	if (!glfwInit())
		return;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (!m_Window)
	{
		glfwTerminate();
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_Window);

	/* init glew */
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* problem: glewinit failed, something is seriously wrong. */
		fprintf(stderr, "error: %s\n", glewGetErrorString(err));
	}

	/* Print Infos */
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_VENDOR) << std::endl;

	glClearColor(0.0f, 0.f, 0.f, 1.f);
}

std::string OpenGlWindow::GetTitle() const
{
	return m_Title;
}

unsigned int OpenGlWindow::GetWidth() const
{	
	return m_Width;
}

unsigned int OpenGlWindow::GetHeight() const
{ 
	return m_Height;
}

void OpenGlWindow::Show()
{
	ShaderProgram program("resources/BasicVertex.shader", "resources/BasicFragment.shader");
	program.Bind();

	CubeMesh mesh;
	Model model1(mesh);
	Model model2(mesh);

	float aspectRatio = 1920.f / 1080.f;

	glm::mat4 projection = glm::perspective(glm::radians(55.f), aspectRatio, 0.1f, 100.f);
	/*glm::mat4 projection = glm::ortho(-10.f * aspectRatio, 10.f * aspectRatio, -10.f, 10.f, 10.0f, -10.f);*/
	program.SetProjectionMatrix(projection);
	
	glm::mat4 camera = glm::lookAt(glm::vec3(0.f, 3.f, 0.f), glm::vec3(0.f, 3.f, -1.f), glm::vec3(0.f, 1.f, 0.f));
	program.SetViewMatrix(camera);	

	glEnable(GL_DEPTH_TEST);	

	Transform& trans1 = model1.GetTransform();	
	trans1.SetTranslation(1.f, 0.f, -5.f);		

	Transform& trans2 = model2.GetTransform();
	trans2.SetTranslation(-1.f, 1.f, -5.f);

	float angleY = 0.0f;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(m_Window))
	{
		angleY += 0.05f;

		if (angleY > 360.0f)
		{
			angleY = 0.0f;
		}

		trans1.SetRotation(angleY, angleY, angleY);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		model1.Draw(program);
		model2.Draw(program);

		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}

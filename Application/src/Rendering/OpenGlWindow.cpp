#include "OpenGlWindow.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

OpenGlWindow::OpenGlWindow(const std::string& title, unsigned int width, unsigned int height)
	:m_Title(title), m_Width(width), m_Height(height)
{
	/* Initialize the library */
	if (!glfwInit())
		return;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(m_Window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);		

		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}
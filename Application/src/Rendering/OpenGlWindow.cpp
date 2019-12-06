#include "OpenGlWindow.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Model.h"
#include "OpenGlVertexBuffer.h"
#include "ShaderProgram.h"

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
	Model model;
	OpenGlVertexBuffer buffer(model);
	buffer.Bind();		

	unsigned int indices[] = {
		0, 1, 3, 0, 2, 3
	};

	GLuint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);


	ShaderProgram program("resources/BasicVertex.shader", "resources/BasicFragment.shader");
	program.Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);	

	Transform& trans = model.GetTransform();

	trans.SetTranslation(0.f, 0.f, -20.f);
	//trans.SetScale(20.f, 20.f, 20.f);
	
	program.SetModelMatrix(model);

	float aspectRatio = 1920.f / 1080.f;

	glm::mat4 perspective = glm::perspective(65.f, aspectRatio, 0.1f, 100.f);
	//glm::mat4 orthographic = glm::ortho(-100.f * ratio, 100.f * ratio, -100.f, 100.f, 1.0f, -1.f);

	program.SetProjectionMatrix(perspective);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(m_Window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);			

		// Index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

		// Draw the triangles !
		glDrawElements(
			GL_TRIANGLES,      // mode
			6,					// count
			GL_UNSIGNED_INT,   // type
			(void*)0           // element array buffer offset
		);

		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}

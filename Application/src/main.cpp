#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "ShaderProgram.h"

int main(void)
{
	GLFWwindow* window;	

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}		

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

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

	ShaderProgram program = ShaderProgram("res/shaders/Basic.shader");
	program.Bind();

	glClearColor(0.0f, 0.f, 0.f, 1.f);

	/* Dreieck */
	GLuint triangleBuffer;
	glGenBuffers(1, &triangleBuffer);

	float points[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), points, GL_STATIC_DRAW);	

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);		
		
		glDrawArrays(GL_TRIANGLES, 0, 3);		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);	


		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
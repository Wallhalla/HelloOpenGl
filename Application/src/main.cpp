#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

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

	glClearColor(0.0f, 0.f, 0.f, 1.f);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
			glVertex3f(1, 0, 0);			
			glVertex3f(0, 1, 0);				
			glVertex3f(0, 0, 1);			
		glEnd();		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);	


		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
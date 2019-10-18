#include "GLFW/glfw3.h"
#include <iostream>
int main(void)
{
	GLFWwindow* window;	

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
			glVertex3f(1, 0, 0);
			glColor3f(1, 0, 1);
			glVertex3f(0, 1, 0);	
			glColor3f(1, 1, 1);
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
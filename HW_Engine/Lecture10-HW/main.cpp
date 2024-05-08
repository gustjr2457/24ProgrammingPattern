#include <iostream>
#include <GLFW/glfw3.h>
#include <random>
#include <cmath>
#pragma comment(lib, "Opengl32.lib")


void errorCallback(int error, const char* description)
{
	std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int initialize()
{

	return 0;
}

int release()
{
	return 0;
}

int update()
{
	return 0;
}

int render(double rad)
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2d(0, 0);
	glVertex2d(0.5 * cos(rad), 0.5 * sin(rad));
	glEnd();
	return 0;
}

int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(800, 800, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	double rd = 0.001f;
	initialize();
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render(rd);
		rd += 0.001f;
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}
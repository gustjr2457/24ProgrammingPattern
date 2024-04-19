#include <iostream>
#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <random>

#include "MSList.h"
#include "Star.hpp"


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

MSList<MObject*> list;

int initialize()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> randPos(-1.0f, 1.0f);
	std::uniform_real_distribution<float> randColor(0.0f, 1.0f);
	for (int i = 0; i < 300; i++)
	{
		float posX = randPos(gen);
		float posY = randPos(gen);
		float r = randColor(gen);
		float g = randColor(gen);
		float b = randColor(gen);
		list.push_back(new Star(posX, posY, r, g, b));
	}
	
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

int render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 300; i++)
	{
		MObject* a = list[i];
		a->render();
	}

	return 0;
}

int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}
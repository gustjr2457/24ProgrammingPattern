﻿#include <iostream>
#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include <cmath>

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
const double PI = 3.1415926;
int initialize()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> randPos(-1.4f, 1.4f);
	std::uniform_real_distribution<float> randColor(0.0f, 1.0f);
	for (int i = 0; i < 300; i++)
	{
		double posX = randPos(gen);
		double posY = randPos(gen);
		double r = randColor(gen);
		double g = randColor(gen);
		double b = randColor(gen);
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

int render(double rad)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glRotated(0.1, 0, 0, 1);
	for (int i = 0; i < 300; i++)
	{
		MObject* a = list[i];
		a->render(rad);
	}

	return 0;
}

int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 720, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	initialize();
	double rd = 1.0f;
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render(rd);
		rd += 1.0f;
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}
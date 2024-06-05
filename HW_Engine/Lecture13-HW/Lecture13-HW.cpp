#include <iostream>
#include <GLFW/glfw3.h>
#include <random>
#include <cmath>
#include <vector>
#pragma comment(lib, "Opengl32.lib")

using namespace std;

const double gravity = 9.8;

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

class Player
{
public:
	void renderPlayer()
	{
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(posX - 30.0f, posY + 30.0f);
		glVertex2f(posX, posY + 30.0f);
		glVertex2f(posX, posY);
		glVertex2f(posX - 30.0f, posY);
		glEnd();
	}

	void jumpPlayer()
	{
		if (posY <= -100 && posY <= 50)
		{
			while (posY <= 50)
			{
				posY += gravity;
			}
		}
	}

	bool IsPosYzero()
	{
		if (posY <= -100)
			return true;
		else
			return false;
	}


public:
	float posY = -100.0f;
	float posX = -270.0f;

};

class Ground
{
public:
	void renderGround()
	{

	}
private:
	float posY = -100.0f;
};


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

void render()
{

	glColor3f(0, 1, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-640, -360);
	glVertex2f(640, -360);
	glVertex2f(640, -100);
	glVertex2f(-640, -100);
	glEnd();

}



int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 720, "Rrrrrrrrrrrrr", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	initialize();
	Player p1;
	bool IsPlayerJump = false;

	while (!glfwWindowShouldClose(window))
	{

		glfwSwapInterval(1);
		glViewport(0, 0, 1280, 720);  // 뷰포트 설정
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 1280, 0, 720, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(1280 / 2, 720 / 2, 0);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		update();
		render();
		p1.renderPlayer();

		
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) 
			IsPlayerJump = true;
		
		if (IsPlayerJump)
		{
			p1.jumpPlayer();
			IsPlayerJump = false;
		}
		if (!p1.IsPosYzero())
		{
			p1.posY -= gravity;
		}
		
		if (p1.posY < -100.0f)
		{
			p1.posY = -100.0f;
		}
		

		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}
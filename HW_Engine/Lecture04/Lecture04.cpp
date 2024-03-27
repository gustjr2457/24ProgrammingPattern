#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;
// 라이브러리 종속성 추가
#pragma comment(lib, "opengl32.lib")

// idle : 화면색 검정색으로 clear
// 마우스 오른쪽 keyDown 하면 : 빨간색
// 마우스 오른쪽 keyUp 하면 : 원상복구
// 마우스 왼쪽 keyDown 하면 : 빨간색
// 마우스 왼쪽 keyUp 하면 : 원상복구
// 마우스 왼쪽 keyDown하고 드래그 중이면 : 파랑색
// 마우스 왼쪽 keyDown하고 드래그 중이면 : 마젠타색



void errorCallback(int error, const char* description)
{
    cerr << "GLFW Error: " << description << endl;
}

void mouse_posCallBack(GLFWwindow* window, double xpos, double ypos) {

}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}


int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    GLFWwindow* window;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 768, "PP_Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mouse_posCallBack);
    glfwSetMouseButtonCallback(window, mouseCallback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();
        //glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
using namespace std;
// 라이브러리 종속성 추가
#pragma comment(lib, "opengl32.lib")

// idle : 화면색 검정색으로 clear
// 마우스 오른쪽 keyDown 하면 : 빨간색
// 마우스 오른쪽 keyUp 하면 : 원상복구
// 마우스 왼쪽 keyDown 하면 : 초록색
// 마우스 왼쪽 keyUp 하면 : 원상복구
// 마우스 왼쪽 keyDown하고 드래그 중이면 : 파랑색
// 마우스 왼쪽 keyDown하고 드래그 중이면 : 마젠타색


double prevMouseX = 0.0;
double prevMouseY = 0.0;
bool LorR = true;


void errorCallback(int error, const char* description)
{
    cerr << "GLFW Error: " << description << endl;
}

bool approximatelyEqual(double a, double b, double epsilon) {
    return fabs(a - b) <= epsilon;
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (prevMouseX != 0.0 && prevMouseY != 0.0) {
        if (approximatelyEqual(xpos, prevMouseX, 1) && approximatelyEqual(ypos, prevMouseY, 1)) {
            if (LorR)
                glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
            else
                glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

        }
        else
        {
            if (LorR)
                glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
            else
                glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

        }
    }

    prevMouseX = xpos;
    prevMouseY = ypos;
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
        LorR = true;
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glfwSetCursorPosCallback(window, mouse_callback);
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glfwSetCursorPosCallback(window, nullptr);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        LorR = false;
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glfwSetCursorPosCallback(window, mouse_callback);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glfwSetCursorPosCallback(window, nullptr);
    }
}


int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "PP_Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseCallback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}
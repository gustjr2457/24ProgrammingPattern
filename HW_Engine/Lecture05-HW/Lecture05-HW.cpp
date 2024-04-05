#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
#pragma comment(lib, "opengl32.lib")

using namespace std;

double prevMouseX = 0.0;
double prevMouseY = 0.0;
bool LorR = true;
float moveSideFactor = 0.0f;
float moveUDFactor = 0.0f;
float scaleFactor = 1.0f;



void errorCallback(int error, const char* description)
{
    cerr << "GLFW Error: " << description << endl;
}

bool approximatelyEqual(double a, double b, double epsilon)
{
    return abs(a - b) <= epsilon;
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    
    if (LorR)
    {
        if (prevMouseX - xpos > 0 && prevMouseX != 0.0)
            moveSideFactor -= abs(prevMouseX - xpos) * 0.0015f;
        else if (prevMouseX - xpos < 0 && prevMouseX != 0.0)
            moveSideFactor += abs(prevMouseX - xpos) * 0.0015f;
        if (prevMouseY - ypos > 0 && prevMouseY != 0.0)
            moveUDFactor += abs(prevMouseY - ypos) * 0.0025f;
        else if (prevMouseY - ypos < 0 && prevMouseY != 0.0)
            moveUDFactor -= abs(prevMouseY - ypos) * 0.0025f;
    }
    else if (LorR == false)
    {
        if (prevMouseX - xpos > 0 && prevMouseX != 0.0)
        {
            /*
            scaleFactor -= 0.01f;
            glTranslatef(xpos * 0.000001, ypos * 0.000001, 0.0f);*/
            glScalef(0.9f, 0.9f, 1.0f);
        }
        else if (prevMouseX - xpos < 0 && prevMouseX != 0.0)
        { 

            //scaleFactor += 0.01f;
            //glTranslatef(xpos * -0.000001, ypos * -0.000001, 0.0f);
            glScalef(1.1f, 1.1f, 1.0f);
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
        glfwSetCursorPosCallback(window, mouse_callback);
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        prevMouseX = 0.0;
        prevMouseY = 0.0;
        glfwSetCursorPosCallback(window, nullptr);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        LorR = false;
        glfwSetCursorPosCallback(window, mouse_callback);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        prevMouseX = 0.0;
        prevMouseY = 0.0;
        glfwSetCursorPosCallback(window, nullptr);
    }
}

int render()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f((-0.45f + moveSideFactor) * scaleFactor, (0.0f + moveUDFactor) * scaleFactor);
    glVertex2f((-0.10f + moveSideFactor) * scaleFactor, (0.0f + moveUDFactor) * scaleFactor);
    glVertex2f((-0.28f + moveSideFactor) * scaleFactor, (-0.24f + moveUDFactor) * scaleFactor);
    glEnd();
    // 중점 (-0.27666, -0.08)


    glBegin(GL_TRIANGLES);

    glVertex2f((-0.27f + moveSideFactor) * scaleFactor, (0.22f + moveUDFactor) * scaleFactor);
    glVertex2f((-0.39f + moveSideFactor) * scaleFactor, (-0.40f + moveUDFactor) * scaleFactor);
    glVertex2f((-0.21f + moveSideFactor) * scaleFactor, (-0.15f + moveUDFactor) * scaleFactor);
    glEnd();
    // 중점 (-0.29, -0.11)
    
    glBegin(GL_TRIANGLES);

    glVertex2f((-0.45f + moveSideFactor) * scaleFactor, (0.0f + moveUDFactor) * scaleFactor);
    glVertex2f((-0.23f + moveSideFactor) * scaleFactor, (0.0f + moveUDFactor) * scaleFactor);
    glVertex2f((-0.15f + moveSideFactor) * scaleFactor, (-0.40f + moveUDFactor) * scaleFactor);
    glEnd();
    // 중점 (-0.27666, 0.13333)

    return 0;
}

int main(void)
{
    if (!glfwInit())
        return -1;


    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "PP_Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }



    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseCallback);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glMatrixMode(GL_MODELVIEW);
        glClear(GL_COLOR_BUFFER_BIT);
        render();
        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}
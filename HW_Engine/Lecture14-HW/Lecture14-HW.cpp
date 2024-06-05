#include <GLFW/glfw3.h>
#include <iostream>
#pragma comment(lib, "Opengl32.lib")

// 플레이어의 상태를 나타내는 구조체
struct Player {
    float position;  // y 좌표
    float velocity;  // y 방향 속도
    bool isJumping;
};

// 게임 내 설정값
const float gravity = 9.8f;         // 중력 가속도 (m/s^2)
const float jumpVelocity = 10.0f;    // 점프 초기 속도 (m/s)
const float groundLevel = -100.0f;  // 땅의 y 좌표 (픽셀)
const float pixelPerMeter = 50.0f;  // 1미터당 픽셀 수
const float deltaTime = 0.016f;     // 프레임 시간 (초)

// 플레이어 초기화
Player player = { -100.0f, 0.0f, false };

void updatePlayer() {
    if (player.isJumping) {
        // 중력 적용 (픽셀/초^2)
        player.velocity -= gravity * pixelPerMeter * deltaTime;
        player.position += player.velocity * deltaTime;

        // 땅에 도착하면 속도와 점프 상태 초기화
        if (player.position <= groundLevel) {
            player.position = groundLevel;
            player.velocity = 0.0f;
            player.isJumping = false;
        }
    }
}

void renderPlayer() {
    glPushMatrix();
    glTranslatef(0.0f, player.position, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-270.0f, -100.0f);
    glVertex2f(-270.0f, -80.0f);
    glVertex2f(-250.0f, -80.0f);
    glVertex2f(-250.0f, -100.0f);
    glEnd();
    glPopMatrix();
}

void renderGround() {
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-640.0f, -200.0f);
    glVertex2f(-640.0f, -360.0f);
    glVertex2f(640.0f, -360.0f);
    glVertex2f(640.0f, -200.0f);
    glEnd();
    glPopMatrix();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        if (!player.isJumping) {
            player.isJumping = true;
            player.velocity = jumpVelocity * pixelPerMeter;
        }
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Jumping Player", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);

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

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        renderGround();
        updatePlayer();
        renderPlayer();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

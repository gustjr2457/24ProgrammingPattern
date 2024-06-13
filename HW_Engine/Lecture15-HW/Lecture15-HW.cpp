#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#pragma comment(lib, "Opengl32.lib")
// 기본 오브젝트 클래스 정의
class Object {
public:
    float x, y;       // 중심 위치
    float vx, vy;     // 속도
    static const float SIZE; // 물체 크기 (폭과 높이)

    Object(float x = 0, float y = 0, float vx = 0, float vy = 0)
        : x(x), y(y), vx(vx), vy(vy) {}

    virtual void update(float deltaTime, float floorY) {
        // 기본 객체는 아무런 업데이트도 하지 않음
    }

    virtual void render() {
        // 기본 객체는 아무것도 렌더링하지 않음
    }
};

const float Object::SIZE = 20.0f; // 물체 크기 (폭과 높이)

// 중력 적용 객체 클래스 정의
class GravityObject : public Object {
public:
    float mass;      // 질량
    static const float GRAVITY; // 중력 상수
    static const float PIXELS_PER_METER; // 1미터당 픽셀 수

    GravityObject(float mass, float x = 0, float y = 0, float vx = 0, float vy = 0)
        : Object(x, y, vx, vy), mass(mass) {}

    void update(float deltaTime, float floorY) override {
        // 중력 가속도를 속도에 적용
        vy -= GRAVITY * deltaTime;

        // 속도를 위치에 적용
        x += vx * deltaTime * PIXELS_PER_METER;
        y += vy * deltaTime * PIXELS_PER_METER;

        // 바닥에 닿으면 위치와 속도 조정
        if (y - SIZE / 2 < floorY) {
            y = floorY + SIZE / 2;
            vy = 0;
        }
    }

    void render() override {
        // 물체의 위치를 초록색 사각형으로 렌더링
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x - SIZE / 2, y - SIZE / 2);
        glVertex2f(x + SIZE / 2, y - SIZE / 2);
        glVertex2f(x + SIZE / 2, y + SIZE / 2);
        glVertex2f(x - SIZE / 2, y + SIZE / 2);
        glEnd();
    }
};

const float GravityObject::GRAVITY = 9.8f;
const float GravityObject::PIXELS_PER_METER = 50.0f;

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // GLFW 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Gravity Example", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // V-sync 활성화

    // OpenGL 설정
    glViewport(0, 0, 1280, 720);  // 뷰포트 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1280, 0, 720, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1280 / 2, 720 / 2, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // 물체 생성
    std::vector<Object*> objects;
    objects.push_back(new GravityObject(1.0f, -100, 720 / 2, 0.0f, 0.0f));
    objects.push_back(new GravityObject(2.0f, 0, 720 / 2, 0.0f, 0.0f));

    // 바닥 높이 (픽셀 단위)
    float floorY = -300;

    // 시간 측정용 변수
    float lastTime = glfwGetTime();

    // 메인 루프
    while (!glfwWindowShouldClose(window)) {
        // 현재 시간 계산
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // 물체 업데이트
        for (auto obj : objects) {
            obj->update(deltaTime, floorY);
        }

        // 렌더링
        glClear(GL_COLOR_BUFFER_BIT);

        // 바닥 렌더링
        glColor3f(1.0f, 1.0f, 1.0f); // 흰색
        glBegin(GL_LINES);
        glVertex2f(-1280.0f / 2.0f, floorY);
        glVertex2f(1280.0f / 2.0f, floorY);
        glEnd();

        // 물체 렌더링
        for (auto obj : objects) {
            obj->render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 메모리 해제
    for (auto obj : objects) {
        delete obj;
    }

    // GLFW 종료
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

#include "MObject.h"
#include <GLFW/glfw3.h>

class Star : public MObject
{
public:
    Star(float initX, float initY, float R, float G, float B)
    {
        _initialX = initX;
        _initialY = initY;
        _red = R;
        _green = G;
        _blue = B;
    }

    ~Star() { }

	void update() { }

	void render()
	{
        glBegin(GL_TRIANGLES);
        glColor3f(_red, _green, _blue);

        glVertex2f(0 + _initialX, 0.05 + _initialY);
        glVertex2f(0 + _initialX, -0.015 + _initialY);
        glVertex2f(-0.030 + _initialX, -0.040 + _initialY);
        glEnd();

        glBegin(GL_TRIANGLES);

        glVertex2f(0 + _initialX, 0.050 + _initialY);
        glVertex2f(0.030 + _initialX, -0.040 + _initialY);
        glVertex2f(0 + _initialX, -0.015 + _initialY);
        glEnd();

        glBegin(GL_TRIANGLES);

        glVertex2f(0 + _initialX, -0.015 + _initialY);
        glVertex2f(0.040 + _initialX, 0.015 + _initialY);
        glVertex2f(-0.040 + _initialX, 0.015 + _initialY);
        glEnd();
	}

private:
    float _initialX;
    float _initialY;
    float _red;
    float _green;
    float _blue;
};
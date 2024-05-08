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

	void render(double rad)
	{
        glPushMatrix();
        glTranslated(_initialX, _initialY, 0);
        glRotated(rad, 0, 0, 1);
        glBegin(GL_TRIANGLES);
        glColor3f(_red, _green, _blue);

        glVertex2f(0 , 0.05);
        glVertex2f(0 , -0.015);
        glVertex2f(-0.030, -0.040);
        glEnd();

        glBegin(GL_TRIANGLES);

        glVertex2f(0, 0.050);
        glVertex2f(0.030, -0.040);
        glVertex2f(0, -0.015);
        glEnd();

        glBegin(GL_TRIANGLES);

        glVertex2f(0, -0.015);
        glVertex2f(0.040, 0.015);
        glVertex2f(-0.040, 0.015);
        glEnd();
        glTranslatef(-_initialX, -_initialY, 0);
        glPopMatrix();
	}

private:
    double _initialX;
    double _initialY;
    double _red;
    double _green;
    double _blue;
};
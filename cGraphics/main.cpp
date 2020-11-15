#include <GLFW/glfw3.h>

#include "src/headers/Window.h"



int main(void)
{
    Engine::Window win("Test", 1000, 800);

    while (!win.closed())
    {
        win.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        win.update();
    }

    return 0;
}
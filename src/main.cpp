#include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <ft2build.h>
#include "utils/Window.h"

// using namespace std;

int WinMain()
{
    Window *win = new Window(800, 600, "Hello World");

    while (!win->shouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        win->update();
    }

    return 0;
}
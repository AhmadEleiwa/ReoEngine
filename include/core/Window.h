#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
    GLFWwindow *window;

public:
    Window();
    Window(int width, int height, const char *title);
    ~Window();
    void update();
    bool shouldClose();
    GLFWwindow *getWindow();
};
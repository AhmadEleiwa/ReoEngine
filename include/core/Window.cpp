#include "Window.h"
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{

    glViewport(0, 0, width, height);
}
Window::Window(){

};

Window::Window(int width, int height, const char *title)
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwSetWindowPos(window, width / 2, width / 2);
    if (window == NULL)
    {
        std::cout << "Failed to open GLFW window" << std::endl;
        return;
    }
    this->width = width;
    this->height = height;
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void Window::setFullscreen()
{
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0);
}
void Window::setWindowed()
{
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowMonitor(window, NULL, this->width / 2, this->height / 2, this->width, this->height, 0);
}
bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}
void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
Window::~Window()
{
    glfwTerminate();
}

void Window::clear(float r, float g, float b, float a)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(r, g, b, a);
}
int Window::getWidth()
{
    return width;
}
int Window::getHeight()
{
    return height;
}

bool Window::getKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

GLFWwindow *Window::getWindow()
{
    return window;
}
void Window::closeWindow()
{
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
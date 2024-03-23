#include "Window.h"
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{

    glViewport(0, 0, width, height);
}
Window::Window() {

};

Window::Window(int width, int height, const char* title) {
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    std::string str = "Reo Engine";
    window = glfwCreateWindow(800, 600, str.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to open GLFW window" << std::endl;
        return ;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return ;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}
bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}
void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}
Window::~Window() {
    glfwTerminate();
}
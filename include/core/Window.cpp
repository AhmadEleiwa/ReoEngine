#include "Window.h"
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{

    glViewport(0, 0, width, height);
}
Window::Window(){

};
/**
 * Constructor for the Window class.
 *
 * @param width The width of the window.
 * @param height The height of the window.
 * @param title The title of the window.
 *
 * @throws None
 */
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
    glfwSetWindowPos(window, width / 2, height / 2);
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
/**
 * Sets the window to fullscreen mode.
 *
 * @return void
 *
 * @throws None
 */
void Window::setFullscreen()
{
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0);
}
/**
 * Sets the window to windowed mode.
 *
 * @return void
 *
 * @throws None
 */
void Window::setWindowed()
{
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowMonitor(window, NULL, this->width / 2, this->height / 2, this->width, this->height, 0);
}
/**
 * Check if the window should close.
 *
 * @return true if the window should close, false otherwise
 */
bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}
/**
 * Updates the window by swapping the front and back buffers and processing any pending events.
 *
 * @throws None
 */
void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
Window::~Window()
{
    glfwTerminate();
}
/**
 * Clears the window with the specified color.
 *
 * @param r The red component of the color.
 * @param g The green component of the color.
 * @param b The blue component of the color.
 * @param a The alpha component of the color.
 */
void Window::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
/**
 * @brief Requests user attention to the window
 *
 * This function requests user attention to the window. On platforms where this is
 * supported, it mark the window as a candidate for attention. Current
 * functionality is to flash the window title bar red if the window does not
 * have input focus. If the window already has input focus, this function
 * does nothing.
 *
 * For example, if the user is currently focused on another window, the
 * window manager may choose to blink the title bar of the target window to
 * draw the user's attention to it.
 */
void Window::requestAttention()
{
    glfwRequestWindowAttention(window);
}
/**
 * Retrieves the width of the window.
 *
 * @return The width of the window.
 */
int Window::getWidth()
{
    return width;
}
/**
 * Retrieves the height of the window.
 *
 * @return The height of the window.
 */
int Window::getHeight()
{
    return height;
}
/**
 * Get the status of a specific key press.
 *
 * @param key the key code to check
 *
 * @return true if the key is pressed, false otherwise
 */
bool Window::getKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}
/**
 * Retrieves the GLFWwindow object associated with the Window.
 *
 * @return A pointer to the GLFWwindow object.
 */
GLFWwindow *Window::getWindow()
{
    return window;
}
/**
 * Closes the window by setting the window should close flag to true.
 */
void Window::closeWindow()
{
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
/**
 * Sets the position of the window.
 *
 * @param x the x-coordinate position
 * @param y the y-coordinate position
 *
 * @return void
 *
 * @throws None
 */
void Window::setPosition(double x, double y)
{
    glfwSetWindowPos(window, x, y);
}
/**
 * Sets the cursor mode for the window.
 *
 * @param mode the cursor mode to set
 *
 * @throws None
 */
void Window::setCursorMode(int mode)
{
    glfwSetInputMode(window, GLFW_CURSOR, mode);
}
/**
 * Sets the cursor position for the window.
 *
 * @param x The x-coordinate of the cursor position
 * @param y The y-coordinate of the cursor position
 *
 * @return void
 *
 * @throws ErrorType None
 */
void Window::setCursorPosition(double x, double y)
{
    glfwSetCursorPos(window, x, y);
}
/**
 * Sets the callback function for cursor position updates.
 *
 * @param callback The callback function to set
 *
 * @return void
 *
 * @throws ErrorType If the window or callback is invalid
 */
void Window::setCursorPosCallback(GLFWcursorposfun callback)
{
    glfwSetCursorPosCallback(window, callback);
}
/**
 * Sets the mouse button callback for the window.
 *
 * @param callback The function to be called when a mouse button is pressed or released.
 *
 * @return void
 *
 * @throws None
 */
void Window::setMouseButtonCallback(GLFWmousebuttonfun callback)
{
    glfwSetMouseButtonCallback(window, callback);
}
/**
 * Sets the scroll callback for the window.
 *
 * @param callback the scroll callback function to be set
 *
 * @throws ErrorType description of error
 */
void Window::setScrollCallback(GLFWscrollfun callback)
{
    glfwSetScrollCallback(window, callback);
}
/**
 * Sets the key callback function for the Window.
 *
 * @param callback the function pointer to the key callback function
 *
 * @return void
 *
 * @throws None
 */
void Window::setKeyCallback(GLFWkeyfun callback)
{
    glfwSetKeyCallback(window, callback);
}
/**
 * Sets the character callback function for the GLFW window.
 *
 * @param callback The function pointer to the character callback.
 *
 * @return void
 *
 * @throws None
 */
void Window::setCharCallback(GLFWcharfun callback)
{
    glfwSetCharCallback(window, callback);
}
/**
 * Set the callback function for window content scale changes.
 *
 * @param callback The callback function to set
 *
 * @return void
 *
 * @throws ErrorType None
 */
void Window::setWindowContentScaleCallback(GLFWwindowcontentscalefun callback)
{
    glfwSetWindowContentScaleCallback(window, callback);
}
/**
 * Sets the callback function for the window position event.
 *
 * @param callback The callback function to be set.
 *
 * @return void
 *
 * @throws None
 */
void Window::setWindowPosCallback(GLFWwindowposfun callback)
{
    glfwSetWindowPosCallback(window, callback);
}
/**
 * Sets the framebuffer size callback for the window.
 *
 * @param callback the callback function to be called when the framebuffer size changes
 *
 * @throws ErrorType description of error
 */
void Window::setFramebufferSizeCallback(GLFWframebuffersizefun callback)
{
    glfwSetFramebufferSizeCallback(window, callback);
}
/**
 * Set the callback function for when the window gains or loses focus.
 *
 * @param callback The function to be called when the window gains or loses focus
 *
 * @return void
 *
 * @throws ErrorType None
 */
void Window::setWindowFocusCallback(GLFWwindowfocusfun callback)
{
    glfwSetWindowFocusCallback(window, callback);
}
/**
 * Sets the window refresh callback for the GLFW window.
 *
 * @param callback the function pointer to the GLFW window refresh callback
 *
 * @return void
 *
 * @throws None
 */
void Window::setWindowRefreshCallback(GLFWwindowrefreshfun callback)
{
    glfwSetWindowRefreshCallback(window, callback);
}
/**
 * Sets the callback for when the window is about to close.
 *
 * @param callback The function to be called when the window is about to close
 *
 * @return void
 *
 * @throws ErrorType None
 */
void Window::setWindowCloseCallback(GLFWwindowclosefun callback)
{
    glfwSetWindowCloseCallback(window, callback);
}
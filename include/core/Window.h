#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb_image.h>
class Window
{
private:
    GLFWwindow *window;
    int width, height;
    const char *title;

public:
    Window();
    Window(int width, int height, const char *title);
    ~Window();
    void update();
    bool shouldClose();
    void clear(float r, float g, float b, float a);
    GLFWwindow *getWindow();
    int getWidth();
    int getHeight();
    bool getKeyPressed(int key);
    void closeWindow();
    void setFullscreen();
    void setWindowed();

    void setPosition(double x, double y);
    void setCursorMode(int mode);
    void setCursorPosition(double x, double y);
    void requestAttention();
    void setWindowIcon(const char *path);
    // void setWindowIcon(GLFWimage *images, int count);

    void setCursorPosCallback(GLFWcursorposfun callback);
    void setMouseButtonCallback(GLFWmousebuttonfun callback);
    void setScrollCallback(GLFWscrollfun callback);
    void setKeyCallback(GLFWkeyfun callback);
    void setCharCallback(GLFWcharfun callback);
    void setWindowCloseCallback(GLFWwindowclosefun callback);
    void setWindowRefreshCallback(GLFWwindowrefreshfun callback);
    void setWindowFocusCallback(GLFWwindowfocusfun callback);
    void setWindowPosCallback(GLFWwindowposfun callback);
    void setFramebufferSizeCallback(GLFWframebuffersizefun callback);
    void setWindowContentScaleCallback(GLFWwindowcontentscalefun callback);

};
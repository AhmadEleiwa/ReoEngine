// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <ft2build.h>
// #include <core/Window.h>

#include <ui/Text.h>
#include "core/Window.h"
#include "core/Program.h"

// #include <Windows.h>
// using namespace std;
int main()
{

    // TCHAR buffer[MAX_PATH];
    // GetCurrentDirectory(MAX_PATH, buffer);
    // std::cout << buffer << std::endl;

    Window *win = new Window(800, 600, "Hello World");

    GLfloat vertices[] = {
        // Positions          // Colors
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom left
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // Bottom right
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // Top
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    Program *prog = new Program("vertix_shader.vs", "fragment_shader.fs");

    while (!win->shouldClose())
    {
        win->clear(1.0f, 0.0f, 0.0f, 1.0f);
        prog->use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        win->update();
    }

    return 0;
}
// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <ft2build.h>
// #include <core/Window.h>

#include <ui/Text.h>
#include "core/Window.h"
#include <core/Camera.h>
// #include "core/Program.h"

// using namespace std;
int main()
{

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
    Program *prog = new Program("shaders/vertix_shader.vs", "shaders/fragment_shader.fs");
    Program *prog2 = new Program("shaders/ui_vertix_shader.vs", "shaders/ui_fragment_shader.fs");

    glm::mat4 projection = glm::mat4(1.0f);

    Camera *camera = new Camera();
    projection = glm::perspective(glm::radians(camera->zoom), (float)win->getWidth() / (float)win->getHeight(), 0.1f, 100.0f);
    glm::mat4 projection2 = glm::ortho(0.0f, (float)win->getWidth(), 0.0f, (float)win->getHeight());
    std::string str = "Score: ";
    Text *text = new Text(str, 0, 0);
    double pox = 0, poy = 0;
    float deltaTime, lastTime;
    while (!win->shouldClose())
    {
        deltaTime = glfwGetTime() - lastTime;
        lastTime = glfwGetTime();
        win->clear(1.0f, 1.0f, 1.0f, 1.0f);
        // prog2->use();
        prog->use();
        prog->setMat4("projection", projection);
        prog->setMat4("view", camera->GetViewMatrix());
        prog->setMat4("model", glm::mat4(1.0f));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        prog2->use();
        prog2->setMat4("projection", projection2);
        text->render(prog2);
        glfwGetCursorPos(win->getWindow(), &pox, &poy);
        camera->ProcessMouseMovement(pox, poy, true);
        if (win->getKeyPressed(GLFW_KEY_S))
        {
            camera->ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
        }
        if (win->getKeyPressed(GLFW_KEY_W))
        {
            camera->ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
        }
        if (win->getKeyPressed(GLFW_KEY_A))
        {
            camera->ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
        }
        if (win->getKeyPressed(GLFW_KEY_D))
        {
            camera->ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
        }

        win->update();
    }

    return 0;
}
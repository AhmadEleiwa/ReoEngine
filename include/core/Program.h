#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class Program
{
private:
    unsigned int id;

public:
    Program(std::string vertexPath, std::string fragmentPath);
    ~Program();
    void setUniform3f(std::string, glm::vec3);
    void setMat4(std::string, glm::mat4);
    void use();
};
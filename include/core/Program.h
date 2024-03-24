#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <windows.h>
class Program
{
private:
    unsigned int id;

public:
    Program(std::string vertexPath, std::string fragmentPath);
    ~Program();
    void use();
};
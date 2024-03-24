#include "Program.h"

Program::Program(std::string vertexPath, std::string fragmentPath)
{


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string vertexCode;
    std::string textLine;
    int success;
    char infoLog[512];

    std::ifstream vertexFile(vertexPath);

    if (vertexFile.is_open())
    {
        while (std::getline(vertexFile, textLine))
        {
            vertexCode += textLine + '\n';
        }
        vertexFile.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << vertexPath << std::endl;
    }

    const char *vertxSource = vertexCode.c_str();
    glShaderSource(vertexShader, 1, &vertxSource, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // -----------------------------------------------------------

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fragmentCode;
    std::ifstream fragmentFile(fragmentPath);
    if (fragmentFile.is_open())
    {
        while (std::getline(fragmentFile, textLine))
        {
            fragmentCode += textLine + '\n';
        }
        fragmentFile.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << fragmentPath << std::endl;
    }

    const char *fragmentSource = fragmentCode.c_str();
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Program::~Program()
{
    glDeleteProgram(this->id);
}

void Program::use()
{
    glUseProgram(this->id);
}
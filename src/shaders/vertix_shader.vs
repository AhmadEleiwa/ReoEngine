#version 330 core
layout (location = 0) in vec3 vertex; 
layout (location = 1) in vec3 color; 



out vec3 outColor;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;



void main()
{
    gl_Position = projection* view* model * vec4(vertex.xyz, 1.0);
    outColor = color;
}
#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>
#include <glm/glm.hpp>
#include <map>
#include <core/Program.h>
struct Character
{
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2 Size;        // Size of glyph
    glm::ivec2 Bearing;     // Offset from baseline to left/top of glyph
    long int Advance;       // Offset to advance to next glyph
};
class Text
{
    std::map<char, Character> Characters;
    unsigned int VAO, VBO;
    std::string text;
    float x, y, scale;
    glm::vec3 color;

public:
    Text(std::string text, float x = 0, float y = 0, float scale = 0.5f, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f), std::string font = "fonts/arial.ttf");
    ~Text() = default;
    void render(Program *program);
    void setText(std::string text);
    std::string getText();
};
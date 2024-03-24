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

    void init(std::string font);

public:
    Text(std::string text);
    Text(std::string text, float x, float y);
    Text(std::string text, float x, float y, float scale);
    Text(std::string text, float x, float y, float scale, glm::vec3 color);
    Text(std::string text, float x, float y, float scale, glm::vec3 color, std::string font);

    ~Text();
    void render(Program *program);
    void setText(std::string text);
    std::string getText();
};
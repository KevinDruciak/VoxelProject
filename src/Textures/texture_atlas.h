#ifndef TEXTURE_ATLAS_H
#define TEXTURE_ATLAS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

#include "texture_loader.h"

class TextureAtlas : public TextureLoader {
public:
    TextureAtlas(const std::string &atlas);
    std::array<GLfloat, 8> getTexture(int x, int y);
private:
    //all hardcoded for now, calculate using a texture pack loader later
    GLfloat image_size{256.0};
    GLfloat texture_size{32.0};
    GLfloat textures_per_line{16.0};
    GLfloat pixel_size{1.0/16.0};
};

#endif

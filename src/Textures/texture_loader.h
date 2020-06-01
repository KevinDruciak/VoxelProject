#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <array>
#include <string>

class TextureLoader {
public:
    TextureLoader() = default;
    TextureLoader(const std::string &texture);
    ~TextureLoader();
    void loadTexture(const std::string &texture);
    void bindTexture();
    GLuint getID();
private:
    GLuint textureID;
};

#endif

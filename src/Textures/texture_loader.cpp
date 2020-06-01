#include <iostream>


#include "Utils/stb_image.h"
#include "texture_loader.h"

TextureLoader::TextureLoader(const std::string &texture) {
    loadTexture(texture);
}

TextureLoader::~TextureLoader() {
    glDeleteTextures(1, &textureID);
}

void TextureLoader::loadTexture(const std::string &texture) {
    //do better loading from file
    glGenTextures(1, &textureID);
    glActiveTexture(GL_TEXTURE0);

    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    //const char* tex = "/Users/kevindruciak/Stuff/VoxelProject/VoxelProject/Resources/test.png\0";
    const char* tex = texture.c_str();
    unsigned char *data = stbi_load(tex, &width, &height, &nrChannels, 0);
    if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);
}

void TextureLoader::bindTexture() {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

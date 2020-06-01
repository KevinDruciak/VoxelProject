#include "voxel_texture.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
/*

REMAKE THIS TO ACTUALLY BE CUBE TEXTURES

*/

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <array>
#include <string>
#include <iostream>

#include "Utils/stb_image.h"


VoxelTexture::VoxelTexture(const std::array<std::string, 6> &textures) {
    //loadTextures(textures);
}

VoxelTexture::~VoxelTexture() {
    glDeleteTextures(1, &textureID);
}

void VoxelTexture::loadTextures(const std::array<std::string, 6> &textures) {
    glGenTextures(1, &textureID);
    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    /*for (int i = 0; i < 6; i++) {
     
     const char* tex = "/Users/kevindruciak/Stuff/VoxelProject/VoxelProject/Resources/test.png\0";
     std::cout << tex << std::endl;
     unsigned char *data = stbi_load(tex, &width, &height, &nrChannels, 0);
     if (data) {
     auto param = GL_TEXTURE_CUBE_MAP_POSITIVE_X + i;
     glTexImage2D(param, 0, GL_RGBA, width, height, 0, GL_RGBA,
     GL_UNSIGNED_BYTE, data);
     glGenerateMipmap(GL_TEXTURE_2D);
     }*/
    
    const char* tex = "C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/Resources/test.png\0";
    unsigned char *data = stbi_load(tex, &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);
    
}

GLuint VoxelTexture::getID() {
    return textureID;
}

void VoxelTexture::bindTextures() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
}

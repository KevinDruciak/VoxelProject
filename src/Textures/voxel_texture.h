/*
 
 REMAKE THIS TO ACTUALLY BE CUBE TEXTURES
 
 */


#ifndef VOXEL_TEXTURE_H
#define VOXEL_TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <array>
#include <string>

class VoxelTexture {
public:
    VoxelTexture() = default;
    VoxelTexture(const std::array<std::string, 6> &textures);
    ~VoxelTexture();
    void loadTextures(const std::array<std::string, 6> & textures);
    void bindTextures();
    GLuint getID();
private:
    GLuint textureID;
};

#endif

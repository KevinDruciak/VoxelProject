#ifndef VOXEL_RENDERER_H
#define VOXEL_RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine/camera.h"
#include "Shader/shader.h"
#include "World/Model/model.h"
#include "Shader/voxel_shader.h"
#include "Textures/voxel_texture.h"
#include <vector>

class VoxelRenderer {
public:
    VoxelRenderer();
        
    void addVoxel(const glm::vec3& pos);
    void renderVoxel(Camera& camera);

private:
    //include support for a texture altas later
    std::vector<glm::vec3> positions;
    Shader ourShader;
    Model* voxel;
    VoxelShader voxelShader;
    VoxelTexture* voxelTexture; //dont use pointer here??
};

#endif


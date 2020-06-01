#include "voxel_renderer.h"

#include <iostream>

VoxelRenderer::VoxelRenderer() {
    voxel = new Model();
    ourShader = ourShader.createShader("C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/Shaders/shader.vs", "C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/Shaders/shader.fs");
    //voxelShader = new VoxelShader("/Users/kevindruciak/Stuff/VoxelProject/VoxelProject/Shaders/shader.vs", "/Users/kevindruciak/Stuff/VoxelProject/VoxelProject/Shaders/shader.fs");
    voxelTexture = new VoxelTexture();
    
    voxelTexture->loadTextures({"test", "test", "test", "test", "test", "test"});
    
    std::vector<GLfloat> texCoords
    {
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        
        0, 1,
        1, 1,
        1, 0,
        0, 0
    };
    std::vector<GLfloat> vertices
    {
        //Back
        1, 0, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0,
        
        //Front
        0, 0, 1,
        1, 0, 1,
        1, 1, 1,
        0, 1, 1,
        
        //Right
        1, 0, 1,
        1, 0, 0,
        1, 1, 0,
        1, 1, 1,
        
        //Left
        0, 0, 0,
        0, 0, 1,
        0, 1, 1,
        0, 1, 0,
        
        //Top
        0, 1, 1,
        1, 1, 1,
        1, 1, 0,
        0, 1, 0,
        
        //Bottom
        0, 0, 0,
        1, 0, 0,
        1, 0, 1,
        0, 0, 1
    };
    
    //do some texture loading bs
    
    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,
        
        4, 5, 6,
        6, 7, 4,
        
        8, 9, 10,
        10, 11, 8,
        
        12, 13, 14,
        14, 15, 12,
        
        16, 17, 18,
        18, 19, 16,
        
        20, 21, 22,
        22, 23, 20
    };
    
    voxel->addData(vertices, texCoords, indices);
    
}

//these are positions not faces
void VoxelRenderer::addVoxel(const glm::vec3& pos) {
    positions.push_back(pos);
}

void VoxelRenderer::renderVoxel(Camera& camera) {
    //ourShader = ourShader.createShader("/Users/kevindruciak/Stuff/VoxelProject/VoxelProject/Shaders/shader.vs", //"/Users/kevindruciak/Stuff/VoxelProject/VoxelProject/Shaders/shader.fs");
    ourShader.use();
    voxel->bindVAO();
    voxelTexture->bindTextures();
    ourShader.setMat4("view", camera.getViewMatrix());
    ourShader.setMat4("projection", camera.getProjectionMatrix());
    
    for (auto& pos : positions) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        ourShader.setMat4("model", model);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
    }
    positions.clear();
}

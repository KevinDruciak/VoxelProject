#include "render_master.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


RenderMaster::RenderMaster() {
    voxelRenderer = new VoxelRenderer();
}

void RenderMaster::drawVoxel(const glm::vec3& pos) {
    voxelRenderer->addVoxel(pos);
}

//void RenderMaster::drawChunk(const glm::vec3& pos) {
//  chunkRenderer->addChunk(pos);
//}

void RenderMaster::finishRender(Camera& camera) {
    glClearColor(0.1, 0.5, 1.0, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    voxelRenderer->renderVoxel(camera);
    //chunkRenderer->renderChunk(camera);


}


#ifndef RENDER_MASTER_H
#define RENDER_MASTER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "voxel_renderer.h"
//#include "chunk_renderer.h"


class RenderMaster {
    public:
    RenderMaster();
    void drawVoxel(const glm::vec3& pos);
    //void drawChunk(const glm::vec3& pos);
    void finishRender(Camera& camera);

    private:
        VoxelRenderer* voxelRenderer;
        //ChunkRenderer* chunkRenderer;
};

#endif

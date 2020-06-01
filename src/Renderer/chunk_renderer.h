#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine/camera.h"
#include "Shader/chunk_shader.h"
//#include "Textures/chunk_texture.h"
#include "render_data.h"
#include "World/Chunk/chunk_mesh.h"

#include <vector>

class ChunkRenderer {
public:
    ChunkRenderer();

    void addChunk(const ChunkMesh& mesh);
    void renderChunk(Camera& camera);

private:
    //include support for a texture altas later
    std::vector<RenderData *> chunks;
    ChunkShader chunkShader;
};

#endif

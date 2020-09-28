#include "WaterRenderer.h"

#include "Engine/Application.h"
#include "Engine/Camera.h"
#include "../World/Block/BlockDatabase.h"
#include "../World/Chunk/ChunkMesh.h"

#include <iostream>

#include "Engine/Application.h"

void WaterRenderer::add(const ChunkMesh &mesh)
{
    m_chunks.push_back(&mesh.getModel().getRenderInfo());
}

void WaterRenderer::render(const Camera &camera)
{
    if (m_chunks.empty()) {
        return;
    }

    glEnable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    m_shader.useProgram();

    m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());
    m_shader.loadTime(g_timeElapsed);

    for (auto mesh : m_chunks) {
		glBindVertexArray(mesh->vao);
		glDrawElements(GL_TRIANGLES, mesh->indicesCount, GL_UNSIGNED_INT, nullptr);
	}

    m_chunks.clear();
}

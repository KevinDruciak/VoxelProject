#include "World/world.h"

World::World(Camera& camera) {
    this->camera = &camera;
    renderMaster = new RenderMaster();
}

void World::render() {
    
    
    for (int i = -50 + camera->getPosition().x; i < 50 + camera->getPosition().x; i++) {
        for (int j = -5; j < -4; j++) {
            for (int k = -50 + camera->getPosition().z; k < 50  + camera->getPosition().z; k++) {
                const glm::vec3 temp = {i, j, k};
                renderMaster->drawVoxel(temp);

            }
        }
    }

    renderMaster->finishRender(*camera);
}



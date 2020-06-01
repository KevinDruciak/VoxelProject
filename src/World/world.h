#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Engine/camera.h"
#include "Renderer/render_master.h"


class World {
public:
    World(Camera& camera);
    void tick(float dt); //check for updates, do later
    void render();
    
private:
    Camera* camera;
    RenderMaster* renderMaster;
};

#endif


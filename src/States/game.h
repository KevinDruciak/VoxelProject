#ifndef GAME_H
#define GAME_H

#include "Engine/camera.h"
#include "World/world.h"


class Game {
public:

    Game(Camera& camera);
    void tick();
    void render();
private:
    Camera* camera;
    World* world;
    //std::vector<
};

#endif

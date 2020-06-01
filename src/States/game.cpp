#include "States/game.h"

Game::Game(Camera &camera) {
    this->camera = &camera;
    this->world = new World(camera);
}
void Game::tick() {
    //camera.tick();
    //world.tick();
    //player.tick();
}

void Game::render() {
    world->render();
}

#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "States/game.h"
#include "States/state_handler.h"
#include "Engine/camera.h"
#include "Inputs/input_handler.h"
#include "Utils/window.h"
#include "Shader/shader.h"
#include "Renderer/render_master.h"

class Engine {
public:
    bool start();
    void run();
    Engine(Camera& camera, InputHandler& inputHandler, Window& window);

private:
    void handle_events();
    void update(StateHandler::GameState *state);
    void render(StateHandler::GameState const &state);
    
    StateHandler* stateHandler;
    Game* game;
    Camera* camera;
    InputHandler* inputHandler;
    Window* window;
    //RenderMaster renderMaster;
};

#endif



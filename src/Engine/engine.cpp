#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <iostream>

#include "engine.h"
#include "Utils/config.h"
//#include "camera.h"
#include "Inputs/input_handler.h"
#include "Utils/window.h"
#include "Renderer/render_master.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std::chrono_literals;

constexpr std::chrono::nanoseconds timestep(1ms);

Engine::Engine(Camera& camera, InputHandler& inputHandler, Window& window) {
    this->camera = &camera;
    this->inputHandler = &inputHandler;
    this->window = &window;
}

bool Engine::start() {
    stateHandler = new StateHandler();
    game = new Game(*camera);
    return true;
}

void Engine::update(StateHandler::GameState *state) {
    //game->tick();
    //check state first
    camera->updateMatrices();
    camera->updateCameraVectors();
}

void Engine::render(StateHandler::GameState const &state) {
    game->render();
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    //glfwSwapBuffers(window->getContext());
    //const glm::vec3 lol ={-1.1, 0, -1.1};
    //renderMaster.drawCube(lol);

    //renderMaster.finishRender(*camera);

    glfwSwapBuffers(window->getContext());
}

void Engine::run() {
    using clock = std::chrono::high_resolution_clock;
    
    std::chrono::nanoseconds lag(0ns);
    auto time_start = clock::now();
    auto timer = clock::now();
    
    StateHandler::GameState current_state;
    StateHandler::GameState previous_state;
    int frames = 0;
    while(!glfwWindowShouldClose(window->getContext())) {
        auto delta_time = clock::now() - time_start;
        time_start = clock::now();
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
        frames++;
        
        // update game logic as lag permits
        while(lag >= timestep) {
            lag -= timestep;
            
            previous_state = current_state;
            update(&current_state); // update at a fixed rate each time
            
        }
        frames++;
        
        if (clock::now() - timer >  std::chrono::duration<long, std::nano> (1000000000)) {
            timer += std::chrono::duration<long, std::nano> (1000000000);
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
        }
        // calculate how close or far we are from the next timestep
        auto alpha = (float) lag.count() / timestep.count();
        auto interpolated_state = stateHandler->interpolate(current_state, previous_state, alpha);
        float dt = std::chrono::duration<float> (delta_time).count();
        inputHandler->processInput(window->getContext(), dt);

        render(interpolated_state);
        glfwPollEvents();

    }
}

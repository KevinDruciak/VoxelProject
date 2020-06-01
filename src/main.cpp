#include <iostream>
#include <iomanip>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Utils/config.h"
#include "Utils/window.h"
#include "Engine/engine.h"
#include "Engine/camera.h"
#include "Inputs/input_handler.h"


#define ERROR -1
#define SUCCESS 0

 
int main() {
    Config config;
	config.loadConfigFromFile("C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/config.txt");
    
    Camera* camera = new Camera();
    InputHandler* inputHandler = new InputHandler(*camera);
    Window* window = new Window(*inputHandler);
    
    Engine* engine = new Engine(*camera, *inputHandler, *window);
    if (engine->start()) {
        engine->run();
    }
    
    glfwTerminate();
    return SUCCESS;
}

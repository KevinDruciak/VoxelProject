#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Utils/config.h"
#include "Engine/camera.h"

class InputHandler {
public:
    InputHandler(Camera& camera);
    void processInput(GLFWwindow *window, float dt);
    void processKeyboard(Camera_Movement direction, float dt);
    void processMouse(double x, double y);
    void processScroll(double y);
private:
    float lastX;
    float lastY;
    bool firstMouse;
    Camera* camera;
    //GLFWwindow* window;
};

#endif

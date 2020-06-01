#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "input_handler.h"
#include <iostream>

InputHandler::InputHandler(Camera& c) {
    camera = &c;
}

void InputHandler::processInput(GLFWwindow *window, float dt) {
    //change later to pause menu
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
        
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        processKeyboard(FORWARD, dt);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        processKeyboard(BACKWARD, dt);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        processKeyboard(LEFT, dt);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        processKeyboard(RIGHT, dt);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        processKeyboard(UP, dt);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        processKeyboard(FAST, dt);
}

void InputHandler::processKeyboard(Camera_Movement direction, float dt) {
    camera->ProcessKeyboard(direction, dt);
}
    
void InputHandler::processMouse(double x, double y) {
    if (firstMouse)
         {
             lastX = x;
             lastY = y;
             firstMouse = false;
         }

         float xoffset = x - lastX;
         float yoffset = lastY - y; // reversed since y-coordinates go from bottom to top

         lastX = x;
         lastY = y;
    
    camera->ProcessMouseMovement(xoffset, yoffset);
}

void InputHandler::processScroll(double y) {
    camera->ProcessMouseScroll(y);
}

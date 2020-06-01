#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "window.h"
#include "config.h"
#include "Inputs/input_handler.h"

Window::Window(InputHandler& inputHandler) {
    this->inputHandler = &inputHandler;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindow = glfwCreateWindow(Config::get().getWidth(),
                                  Config::get().getHeight(), "VoxelProject", NULL, NULL);
    if (glfwWindow == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(glfwWindow);
    glfwSwapInterval(0);
    glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetWindowUserPointer(glfwWindow, this);
    glfwSetFramebufferSizeCallback(glfwWindow, WindowResizeCallback);
    glfwSetCursorPosCallback(glfwWindow, MouseMovedCallback);
    glfwSetScrollCallback(glfwWindow, ScrollMovedCallback);
    

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    

}

auto Window::ViewportDidResize(int w, int h)    -> void {
    glViewport(0, 0, w, h);
}

auto Window::MouseMoved(double x, double y)     -> void {
    inputHandler->processMouse(x, y);
}

auto Window::WheelScrolled(double x, double y)  -> void {
    inputHandler->processScroll(y);
}

GLFWwindow* Window::getContext() {
    return glfwWindow;
}



#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include "Inputs/input_handler.h"

class Window {
public:
    Window(InputHandler& inputHandler);
    auto ViewportDidResize(int w, int h)    -> void;
    auto MouseMoved(double x, double y)     -> void;
    auto WheelScrolled(double x, double y)  -> void;
    GLFWwindow* getContext();

private:
    GLFWwindow* glfwWindow;
    InputHandler* inputHandler;
    
    inline static auto WindowResizeCallback(
                                            GLFWwindow* win, int w, int h) -> void {
        Window *window = static_cast<Window*>(glfwGetWindowUserPointer(win));
        window->ViewportDidResize(w, h);
    }
    
    inline static auto MouseMovedCallback(
                                          GLFWwindow* win, double x, double y) -> void {
        Window *window = static_cast<Window*>(glfwGetWindowUserPointer(win));
        window->MouseMoved(x, y);
    }
    
    inline static auto ScrollMovedCallback(
                                            GLFWwindow* win, double x, double y) -> void {
        Window *window = static_cast<Window*>(glfwGetWindowUserPointer(win));
        window->WheelScrolled(x, y);
    }
};

#endif

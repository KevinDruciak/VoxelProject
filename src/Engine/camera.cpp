#include "camera.h"
#include "Utils/config.h"
#include <iostream>

void Camera::setPosition(glm::vec3 pos) {
    Position = pos;
    //not needed?
}

glm::vec3 Camera::getPosition() {
    return Position;
}

glm::mat4 Camera::getViewMatrix() {
    return view;
}

glm::mat4 Camera::getProjectionMatrix() {
    return projection;
}

void Camera::updateMatrices() {
    projection = glm::perspective(glm::radians(Zoom), (float)Config::get().getWidth() / (float)Config::get().getHeight(), 0.1f, 100.0f);
    view = glm::lookAt(Position, Position + Front, Up);
}


// processes input received from any keyboard-like input system. Accepts input parameter in the form of cameradefined ENUM (to abstract it from windowing systems)
void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
    if (direction == DOWN)
        Position -= Up * velocity;
    if (direction == UP)
        Position += Up * velocity;
    if (direction == FAST)
        Position += Front * velocity;
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(double xoffset, double yoffset, GLboolean constrainPitch) {
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;
    
    Yaw   += xoffset;
    Pitch += yoffset;
    
    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }
    
    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(double yoffset) {
    Zoom -= (double)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}
// calculates the front vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors() {
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up    = glm::normalize(glm::cross(Right, Front));
    updateMatrices();
}

#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    DOWN,
    UP,
    FAST
};

constexpr float YAW         = -90.0f;
constexpr float PITCH       =  0.0f;
constexpr float SPEED       =  20.0f;
constexpr float SENSITIVITY =  0.1f;
constexpr float ZOOM        =  45.0f;

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
        //projection = glm::mat4(1.0f);
        //view = glm::mat4(1.0f);
        //projview = glm::mat4(1.0f);
    }
    // constructor with scalar values
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        projection = glm::mat4(1.0f);
        //view = glm::mat4(1.0f);
        //projview = glm::mat4(1.0f);
        //updateCameraVectors();
    }
    
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    void updateMatrices();
    glm::vec3 getPosition();
    
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(double xoffset, double yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(double yoffset);
    void setPosition(glm::vec3 pos);
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;
    void updateCameraVectors();

private:
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 projview;

};

#endif

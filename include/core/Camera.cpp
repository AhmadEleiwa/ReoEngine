#include "Camera.h"

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, 3.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    yaw = YAW;
    pitch = PITCH;
    movementSpeed = SPEED;
    mouseSensitivity = SENSITIVITY;
    // firstTime = true;
    zoom = ZOOM;
    updateCameraVectors();
}

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->front = glm::normalize(front);
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));
    this->up = glm::normalize(glm::cross(this->right, this->front));
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = this->movementSpeed * deltaTime;
    if (direction == FORWARD)
        this->position += this->front * velocity;
    if (direction == BACKWARD)
        this->position -= this->front * velocity;
    if (direction == LEFT)
        this->position -= this->right * velocity;
    if (direction == RIGHT)
        this->position += this->right * velocity;
}
void Camera::ProcessMouseMovement(float xpos, float ypos, GLboolean constrainPitch)
{
    if (firstTime)
    {
        lastX = xpos;
        lastY = ypos;
        firstTime = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastY = ypos;
    lastX = xpos;
    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(this->position, this->position + this->front, this->up);
}

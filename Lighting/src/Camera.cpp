#include "Camera.h"

Camera::Camera(glm::vec3 position) : cameraPos(position), worldUp(glm::vec3(0.0f, 1.0f, 0.0f)), yaw(-90.0f), pitch(0.0f), speed(2.5f), sensitivity(1.0f), zoom(45.0f), cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
{
	updateCameraVectors();
}
//mouse movement
void Camera::updateCameraDirection(double dx, double dy) 
{
	yaw += dx;
	pitch += dy;
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch > -89.0f) {
		pitch = -89.0f;
	}
	updateCameraVectors();

}
//keyboard input
void Camera::updateCameraPos(Camera_Movement direction, double dt)
{
	float velocity = (float)dt * speed;

	switch (direction) {
	case Camera_Movement::FORWARD:
		cameraPos += cameraFront * velocity;
		break;
	case Camera_Movement::BACKWARD:
		cameraPos -= cameraFront * velocity;
		break;
	case Camera_Movement::RIGHT:
		cameraPos += cameraRight * velocity;
		break;
	case Camera_Movement::LEFT:
		cameraPos -= cameraRight * velocity;
		break;
	case Camera_Movement::UP:
		cameraPos += cameraUp * velocity;
		break;
	case Camera_Movement::DOWN:
		cameraPos -= cameraUp * velocity;
		break;
	}

}
void Camera::updateCameraZoom(double dy) 
{
	if (zoom >= 1.0f && zoom <= 45.0f){
		zoom -= dy;
	}
	else if (zoom < 1.0f) {
		zoom = 1.0f;
	}
	else
	{
		zoom = 45.0f;
	}
}
// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::updateCameraVectors() 
{
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);

	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

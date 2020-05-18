#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT, 
	UP, 
	DOWN
};

class Camera {
public:
	static Camera defaultCamera;

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;
	glm::vec3 worldUp;

	float yaw;
	float pitch;
	float speed;
	float sensitivity;
	float zoom;

	Camera(glm::vec3 position);

	void updateCameraDirection(double dx, double dy);
	//keyboard input
	void updateCameraPos(Camera_Movement movement, double dt);
	void updateCameraZoom(double dy);

	glm::mat4 GetViewMatrix();

private:
	void updateCameraVectors();
};

#endif // !CAMERA_H


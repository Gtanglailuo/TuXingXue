#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp);
	glm::mat4 GetViewMatrix();
	Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldUp);
	void UpdateCameraVectors();
	void ChangeCamera(float x, float y);
	void UpdateCameraFocus();
	glm::vec3 Position;
	glm::vec3 Forward;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	float Pitch, Yaw, speedZ = 0.0f;

};



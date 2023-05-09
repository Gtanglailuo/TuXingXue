#include "Camera.h"
#include <iostream>
Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
{
	Position = position;
	WorldUp = worldUp;
	Forward = glm::normalize(target - position);
	Right = glm::normalize(glm::cross(Forward, worldUp));
	Up = glm::normalize(glm::cross(Right, Forward));
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Forward, WorldUp);
}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldUp)
{
	Position = position;
	WorldUp = worldUp;
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = glm::cos(pitch) * glm::sin(yaw);
	Forward.y = glm::sin(pitch);
	Forward.z = glm::cos(pitch) * glm::cos(yaw);
	Right = glm::normalize(glm::cross(Forward, worldUp));
	Up = glm::normalize(glm::cross(Right, Forward));
	std::cout << Forward.x << "  " << Forward.y << "  " << Forward.z << std::endl;
}

void Camera::UpdateCameraVectors()
{
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Right, Forward));
	//Forward = glm::normalize(Forward);
}

void Camera::ChangeCamera(float x, float y)
{
	float sensitivity = 0.001f;
	Pitch += x * sensitivity;
	Yaw += y * sensitivity;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Yaw < -89.0f)
		Yaw = -89.0f;
	UpdateCameraVectors();
}

void Camera::UpdateCameraFocus()
{
	float sensitivity = 0.01f;
	Position += Forward * sensitivity * speedZ;

}




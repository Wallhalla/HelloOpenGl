#pragma once
#include "GLM/glm.hpp"

class Transform
{
public:
	Transform();

	glm::vec3 GetTranslation() const;
	glm::vec4 GetRotation() const;
	glm::vec4 GetScale() const;

	void SetTranslation(float x, float y, float z);
	void SetRotation(float pitch, float yaw, float roll);
	void SetScale(float x, float y, float z);

private:
	glm::vec3 m_translation;
	glm::vec4 m_rotation;
	glm::vec4 m_scale;
};
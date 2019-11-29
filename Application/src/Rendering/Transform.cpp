#include "Transform.h"

Transform::Transform()	
{
	m_translation = glm::vec3{ 0.f, 0.f, 0.f};
	m_rotation = glm::vec4{ 0.f, 0.f, 0.f, 1.f };
	m_scale = glm::vec4{ 1.f, 1.f, 1.f, 1.f };
}

glm::vec3 Transform::GetTranslation() const
{
	return m_translation;
}

glm::vec4 Transform::GetRotation() const
{
	return m_rotation;
}

glm::vec4 Transform::GetScale() const
{
	return m_scale;
}

void Transform::SetTranslation(float x, float y, float z)
{
	m_translation.x = x;
	m_translation.y = y;
	m_translation.z = z;
}

void Transform::SetRotation(float pitch, float yaw, float roll)
{
	m_rotation.x = pitch;
	m_rotation.y = yaw;
	m_rotation.z = roll;
}

void Transform::SetScale(float x, float y, float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

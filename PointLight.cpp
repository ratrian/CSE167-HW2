#include "PointLight.h"

PointLight::PointLight(glm::vec3 pos, glm::vec3 color, glm::vec3 atten)
{
	PointLight::pos = pos;
	PointLight::color = color;
	PointLight::atten = atten;
	PointLight::mat = glm::mat4(1.0);
}

void PointLight::sendLightToShader(GLuint shader)
{
	glUniform3fv(glGetUniformLocation(shader, "lightPos"), 1, glm::value_ptr(pos));
	glUniform3fv(glGetUniformLocation(shader, "lightCol"), 1, glm::value_ptr(color));
	glUniform3fv(glGetUniformLocation(shader, "lightAtten"), 1, glm::value_ptr(atten));
}

void PointLight::updatePosition(glm::vec3 direction, float rotAngle, glm::vec3 rotAxis)
{
	mat = glm::translate(mat, direction);
	mat = glm::rotate(mat, rotAngle, rotAxis);
	pos = mat * glm::vec4(pos, 1.0);
}
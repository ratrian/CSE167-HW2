#include "PointLight.h"

PointLight::PointLight(glm::vec3 pos, glm::vec3 color, glm::vec3 atten)
{
	PointLight::pos = pos;
	PointLight::color = color;
	PointLight::atten = atten;
}

void PointLight::sendLightToShader(GLuint shader)
{
	glUniform3fv(glGetUniformLocation(shader, "lightPos"), 1, glm::value_ptr(pos));
	glUniform3fv(glGetUniformLocation(shader, "lightCol"), 1, glm::value_ptr(color));
	glUniform3fv(glGetUniformLocation(shader, "lightAtten"), 1, glm::value_ptr(atten));
}
#ifndef _LIGHT_SOURCE_H_
#define _LIGHT_SOURCE_H_

#include "Object.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

class LightSource : public Object
{
private:
	std::vector<glm::vec3> points;
	std::vector<glm::vec3> normals;
	std::vector<glm::ivec3> indices;

	GLuint VAO, VBO, NBO, EBO;

	GLfloat pointSize, normalColoring;

	/*
	 * Attenuation vector consists of
	 *     atten.x = constant factor
	 *     atten.y = linear factor
	 *     atten.z = quadratic factor
	 */
	glm::vec3 pos, color, atten;

public:
	LightSource(std::string objFilename, glm::vec3 pos, glm::vec3 color, glm::vec3 atten);
	~LightSource();

	void draw(const glm::mat4& view, const glm::mat4& projection, GLuint shader);
	void update();
	void orbit(float rotAngle, glm::vec3 rotAxis);
	void move(glm::vec3 s);
};

#endif
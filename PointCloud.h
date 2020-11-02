#ifndef _POINT_CLOUD_H_
#define _POINT_CLOUD_H_

#include "Object.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

class PointCloud : public Object
{
private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> vertexNormals;

	std::vector<glm::ivec3> vIndices;
	std::vector<glm::ivec3> vnIndices;

	GLuint VAO, VBO;
	GLfloat pointSize;

public:
	PointCloud(std::string objFilename, GLfloat pointSize);
	~PointCloud();
	
	void draw(const glm::mat4& view, const glm::mat4& projection, GLuint shader);
	void update();

	void updatePointSize(GLfloat size);
	void spin(float deg);
};

#endif

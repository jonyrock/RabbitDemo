#pragma once
#include "settings.h"

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/gl.h>

class Shaders {
	const Settings& settings;

public:
	Shaders(const Settings& settings)
			: settings(settings) {
	}
	void init();
	~Shaders();

	GLuint programId;
	GLuint vertexPosition_modelspaceId;
	GLuint vertexNormal_modelspaceId;
	
	void update();
	
	void setColor(glm::vec3 color);
	void setModel(glm::mat4 mat);
	void setView(glm::mat4 mat);
	void setProjection(glm::mat4 mat);

private:

	GLuint modelId, viewId, projectionId;
	GLuint colorId, lightColorId;

	GLuint lightTypeId, fillTypeId, ambientId, diffuseId, specularId, specularPowerId, kcId,
			klId, kqId;

	GLuint loadShaders(const char* verPath, const char* fragPath);

};

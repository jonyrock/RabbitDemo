#pragma once
#include "settings.h"
#include "shaders.h"
#include "camera.h"
#include <glm/glm.hpp>

class Scene {
	const Settings& settings;
	Shaders shaders;
	Camera camera;

	GLuint vertexArrayID;
	
	GLuint planeVertexBuffer;
	GLuint planeNormalBuffer;
	GLuint planeSize;

	GLuint rabbitVertexBuffer;
	GLuint rabbitNormalBuffer;
	GLuint rabbitSize;

	glm::mat4 projection;
	glm::mat4 view;

public:
	Scene(const Settings& settings)
			: settings(settings), shaders(settings), camera(settings,
				glm::vec3(0, 3, 3)) {
	}
	void init();
	void update();
	void terminate();
};

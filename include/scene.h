#pragma once
#include "settings.h"
#include "shaders.h"
#include "worldState.h"
#include "camera.h"
#include <GL/glew.h>
#include <glm/glm.hpp>

class Scene {
	const Settings& settings;
	Shaders shaders;
	WorldState worldState;
	
	GLuint planeVerticesBuffer;
	Camera camera;
	glm::mat4 Projection;
	glm::mat4 View;
	
	GLuint vertexbuffer;
	
public:
	Scene(const Settings& settings): 
		settings(settings),
		shaders(settings, worldState),
		camera(0, 10, 10) {
	}
	void init();
	void update();
};
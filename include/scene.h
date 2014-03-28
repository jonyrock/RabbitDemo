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
	
	GLuint vertexbuffer;
	Camera camera;
	glm::mat4 Projection;
	glm::mat4 View;
	
public:
	Scene(const Settings& settings): 
		settings(settings),
		shaders(settings, worldState),
		camera(0, 10, 10) {
	}
	void init();
	void update();
	void terminate();
};
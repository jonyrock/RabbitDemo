#pragma once
#include "settings.h"
#include "worldState.h"

// TODO: remove ol glfw
#include <GL/glew.h>


class Shaders {
	const Settings& settings;
	const WorldState& worldState;
	
	
public:
		
	Shaders(
		const Settings& settings, 
		const WorldState& worldState
	): settings(settings),
	   worldState(worldState) {
	}
	void init();
	
	GLuint programId;
	
	GLuint mvpId;
	GLuint colorId;
	GLuint vertexPosition_modelspaceID;
private:
	GLuint LoadShaders(const char* verPath, const char* fragPath);
	
};
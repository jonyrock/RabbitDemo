#pragma once
#include "settings.h"
#include "worldState.h"

#include <GL/glew.h>
#include <GL/gl.h>

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
	GLuint vertexPosition_modelspaceId;
private:
	GLuint LoadShaders(const char* verPath, const char* fragPath);
	
};
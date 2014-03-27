#pragma once
#include "settings.h"
#include "worldState.h"
#include <GL/glew.h>


class Shaders {
	const Settings& settings;
	const WorldState& worldState;
	GLuint programId;
	
public:
		
	Shaders(
		const Settings& settings, 
		const WorldState& worldState
	): settings(settings),
	   worldState(worldState) {
	}
	void init();
	
	GLuint mvpId;
	GLuint colorId;
	GLuint vertexPosition_modelspaceID;
	
};
#pragma once

#include <GL/glfw.h>
#include <GL/glew.h>

#include <iostream>

using namespace std;

class LightNavigation {
	GLuint _programId;
	
	GLuint _ambientId;
	GLuint _diffuseId;
	
	float _ambient;
	float _diffuse;

public:

	LightNavigation(GLuint programId)
	: _programId(programId) {
		_ambient = 0.5f;
		_diffuse = 0.5f;
		
		_ambientId = glGetUniformLocation(programId, "vertexColor");
		
	}

	inline void windowsIterate() {
		// if (glfwGetKey(GLFW_KEY_KP_ADD) == GLFW_PRESS)
		//     _ts -= 0.1;
		// if (glfwGetKey(GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
		//     _ts += 0.1;
		// glUniform1f(_textureScaleId, _ts);

		// updateParams();
	}
	
private:
	
	inline void updateParams() {
		
	}

	inline void draw() {
		
	}

};
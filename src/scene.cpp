#include "scene.h"
#include "shaders.h"
#include "camera.h"
#include "geom.h"
#include "objloader.h"
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "tools.h"

using namespace std;
using namespace glm;

void Scene::init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	shaders.init();
	
	/** PLANE INIT **/
	vector<vec3> planeVertexPositions;
	fillPlane(planeVertexPositions);

	glGenBuffers(1, &planeVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, planeVertexPositions.size() * sizeof (vec3), 
		&planeVertexPositions[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}

void Scene::update() {
	
	camera.update();
	
	glClearColor(settings.bgColor[0], settings.bgColor[1], settings.bgColor[2], 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(shaders.programId);
	
	// glUniform3f(shaders.colorId, 1.0, 1.0, 1.0);
	
	// glEnableVertexAttribArray(0);
	// glBindBuffer(GL_ARRAY_BUFFER, planeVertexBuffer);
	// glVertexAttribPointer(shaders.vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
	// glDrawArrays(GL_TRIANGLES, 0, 2 * 3);
	
}

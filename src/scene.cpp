#include <GL/glew.h>
#include <GL/gl.h>

#include "scene.h"
#include "shaders.h"
#include "camera.h"
#include "geom.h"
#include "objloader.h"

#include <vector>
#include <iostream>
#include "tools.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

void Scene::init() {

	shaders.init();

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	float NEAR_CLIPPING_PLANE = 0.1f;
	float FAR_CLIPPING_PLANE = 100.0f;
	auto projection = perspective(45.0f, 4.0f / 3.0f, NEAR_CLIPPING_PLANE,
		FAR_CLIPPING_PLANE);

	shaders.setProjection(projection);

	vector<vec3> planeVertices;
	fillPlane(planeVertices);
	planeVertexBufferSize = planeVertices.size();

	vector<vec3> rabbitVertices;
	vector<vec3> rabbitNormals;
	loadOBJ("res/my_rabbit_n.obj", rabbitVertices, rabbitNormals);
	rabbitVertexBufferSize = rabbitVertices.size();

	glGenBuffers(1, &planeVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBuffer);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vec3) * planeVertices.size(),
		&planeVertices[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &rabbitVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitVertexBuffer);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vec3) * rabbitVertices.size(),
		&rabbitVertices[0],
		GL_STATIC_DRAW);

}

void Scene::update() {
	
	glClearColor(settings.bgColor[0], settings.bgColor[1], settings.bgColor[2],
		0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	camera.update();
	shaders.setView(camera.getView());

	// plane
	shaders.setColor(settings.getPlaneColor());
	shaders.setModel(rotate(mat4(10.0f), 90.f, vec3(1, 0, 0)));

	glEnableVertexAttribArray(shaders.vertexPosition_modelspaceId);
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBuffer);
	glVertexAttribPointer(shaders.vertexPosition_modelspaceId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glDrawArrays(GL_TRIANGLES, 0, planeVertexBufferSize * 3);
	glDisableVertexAttribArray(shaders.vertexPosition_modelspaceId);

	// rabbit
	shaders.setColor(settings.getRabbitColor());
	shaders.setModel(mat4(1.0f));

	glEnableVertexAttribArray(shaders.vertexPosition_modelspaceId);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitVertexBuffer);
	glVertexAttribPointer(shaders.vertexPosition_modelspaceId, 3, GL_FLOAT,
	GL_FALSE, 0, NULL);

	glDrawArrays(GL_TRIANGLES, 0, rabbitVertexBufferSize * 3);
	glDisableVertexAttribArray(shaders.vertexPosition_modelspaceId);

}

void Scene::terminate() {
	glDeleteBuffers(1, &planeVertexBuffer);
	glDeleteBuffers(1, &rabbitVertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
}


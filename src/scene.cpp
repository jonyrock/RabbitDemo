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
	camera.init();

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	float NEAR_CLIPPING_PLANE = 0.1f;
	float FAR_CLIPPING_PLANE = 100.0f;
	auto projection = perspective(45.0f, 4.0f / 3.0f, NEAR_CLIPPING_PLANE,
		FAR_CLIPPING_PLANE);

	shaders.setProjection(projection);

	vector<vec3> planeVertices;
	vector<vec3> planeNormals;
	vector<vec3> planeFlatPositions;
	vector<vec3> planeFlatNormals;
	fillPlane(planeVertices);
	for (size_t i = 0; i < planeVertices.size(); i++) {
		planeNormals.push_back(vec3(0, 0, -1));
		planeFlatNormals.push_back(vec3(0, 0, -1));
	}
	for (int i = 0; i < 3; i++)
		planeFlatPositions.push_back(
			(planeVertices[0] + planeVertices[1] + planeVertices[2]) / 3.0f);
	for (int i = 0; i < 3; i++)
		planeFlatPositions.push_back(
			(planeVertices[3] + planeVertices[4] + planeVertices[5]) / 3.0f);

	planeSize = planeVertices.size();

	vector<vec3> rabbitVertices;
	vector<vec3> rabbitNormals;
	loadOBJ("res/rabbit_n.obj", rabbitVertices, rabbitNormals);
	rabbitSize = rabbitVertices.size();
	vector<vec3> rabbitFlatPositions;
	vector<vec3> rabbitFlatNormals;
	for (size_t i = 0; i < rabbitVertices.size(); i += 3) {

		vec3 flatPosition = (rabbitVertices[i] + rabbitVertices[i + 1]
				+ rabbitVertices[i + 2]) / 3.0f;

		rabbitFlatPositions.push_back(flatPosition);
		rabbitFlatPositions.push_back(flatPosition);
		rabbitFlatPositions.push_back(flatPosition);

		vec3 flatNormal = normalize(
			cross(rabbitVertices[i + 1] - rabbitVertices[i],
				rabbitVertices[i + 2] - rabbitVertices[i]));

		rabbitFlatNormals.push_back(flatNormal);
		rabbitFlatNormals.push_back(flatNormal);
		rabbitFlatNormals.push_back(flatNormal);

	}

	/// plane buffers
	glGenBuffers(1, &planeVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBuffer);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vec3) * planeSize, &planeVertices[0],
	GL_STATIC_DRAW);

	glGenBuffers(1, &planeNormalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, planeNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * planeSize, &planeNormals[0],
	GL_STATIC_DRAW);

	glGenBuffers(1, &planeFlatNormalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, planeFlatNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * planeFlatNormals.size(),
		&planeFlatNormals[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &planeFlatPositionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, planeFlatPositionBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * planeFlatPositions.size(),
		&planeFlatPositions[0],
		GL_STATIC_DRAW);

	// rabbit buffers
	glGenBuffers(1, &rabbitVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * rabbitVertices.size(),
		&rabbitVertices[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &rabbitNormalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * rabbitNormals.size(),
		&rabbitNormals[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &rabbitFlatPositionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitFlatPositionBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * rabbitFlatPositions.size(),
		&rabbitFlatPositions[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &rabbitFlatNormalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitFlatNormalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * rabbitFlatNormals.size(),
		&rabbitFlatNormals[0],
		GL_STATIC_DRAW);

}

void Scene::update() {

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClearColor(settings.bgColor[0], settings.bgColor[1], settings.bgColor[2],
		0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera.update();
	shaders.update();

	shaders.setView(camera.getView());

	// plane
	shaders.setColor(settings.getPlaneColor());
	shaders.setModel(
		translate(rotate(mat4(10.0f), 90.f, vec3(1, 0, 0)),
			vec3(0.0f, 0.0f, 0.3f)));

	glEnableVertexAttribArray(shaders.vertexPosition_modelspaceId);
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBuffer);
	glVertexAttribPointer(shaders.vertexPosition_modelspaceId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(shaders.vertexNormal_modelspaceId);
	glBindBuffer(GL_ARRAY_BUFFER, planeNormalBuffer);
	glVertexAttribPointer(shaders.vertexNormal_modelspaceId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(shaders.flatPositionId);
	glBindBuffer(GL_ARRAY_BUFFER, planeFlatPositionBuffer);
	glVertexAttribPointer(shaders.flatPositionId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(shaders.flatNormalId);
	glBindBuffer(GL_ARRAY_BUFFER, planeFlatNormalBuffer);
	glVertexAttribPointer(shaders.flatNormalId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glDrawArrays(GL_TRIANGLES, 0, planeSize * 3);
	glDisableVertexAttribArray(shaders.vertexPosition_modelspaceId);
	glDisableVertexAttribArray(shaders.vertexNormal_modelspaceId);

	// rabbit
	shaders.setColor(settings.getRabbitColor());
	shaders.setModel(glm::translate(glm::mat4(1.0f), vec3(0.2, -0.3f, 0)));

	glEnableVertexAttribArray(shaders.vertexPosition_modelspaceId);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitVertexBuffer);
	glVertexAttribPointer(shaders.vertexPosition_modelspaceId, 3, GL_FLOAT,
	GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(shaders.vertexNormal_modelspaceId);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitNormalBuffer);
	glVertexAttribPointer(shaders.vertexNormal_modelspaceId, 3, GL_FLOAT,
	GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(shaders.flatPositionId);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitFlatPositionBuffer);
	glVertexAttribPointer(shaders.flatPositionId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(shaders.flatNormalId);
	glBindBuffer(GL_ARRAY_BUFFER, rabbitFlatNormalBuffer);
	glVertexAttribPointer(shaders.flatNormalId, 3,
	GL_FLOAT,
	GL_FALSE, 0, (void*) 0);

	glDrawArrays(GL_TRIANGLES, 0, rabbitSize * 3);
	glDisableVertexAttribArray(shaders.vertexPosition_modelspaceId);

}

void Scene::terminate() {
	glDeleteBuffers(1, &planeVertexBuffer);
	glDeleteBuffers(1, &rabbitVertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
}


#include "scene.h"
#include "shaders.h"
#include "camera.h"
#include "geom.h"
#include "objloader.h"
#include <GL/glew.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace glm;

void Scene::init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	shaders.init();

	// View init
	Camera camera(0, 10, 10);

	// Projection inits
	mat4 Model;
	mat4 View;
	float NEAR_CLIPPING_PLANE = 0.1f;
	float FAR_CLIPPING_PLANE = 100.0f;
	Projection = perspective(45.0f, 4.0f / 3.0f, NEAR_CLIPPING_PLANE, FAR_CLIPPING_PLANE);

	mat4 MVP;

	// /** PLANE INIT **/
	// vector<vec3> planeVertices;
	// fillPlane(planeVertices);
	// mat4 planeModel = rotate(mat4(10.0f), 90.f, vec3(1, 0, 0));
	// for (size_t i = 0; i < planeVertices.size(); i++) {
	// 	auto mv = planeModel * vec4(planeVertices[i], 1.f);
	// 	planeVertices[i] = vec3(mv[0], mv[1], mv[2]);
	// }

	// glGenBuffers(1, &planeVerticesBuffer);
	// glBindBuffer(GL_ARRAY_BUFFER, planeVerticesBuffer);
	// glBufferData(GL_ARRAY_BUFFER, planeVertices.size() * sizeof (vec3), &planeVertices[0], GL_STATIC_DRAW);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);

	// /** RABBIT INIT **/
	// vector<vec3> rabbitVertices;
	// vector<vec3> rabbitNormals;

	// if(!loadOBJ(
	// 	"res/my_rabbit_n.obj",
	// 	rabbitVertices,
	// 	rabbitNormals)) {
	// 	exit(2);
	// }

	// GLuint rabbitVertecesBuffer;
	// glGenBuffers(1, &rabbitVertecesBuffer);
	// glBindBuffer(GL_ARRAY_BUFFER, rabbitVertecesBuffer);
	// glBufferData(GL_ARRAY_BUFFER, rabbitVertices.size() * sizeof (vec3), &rabbitVertices[0], GL_STATIC_DRAW);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	// This will identify our vertex buffer
	// vertexbuffer;
	 
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	 
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	 
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	
}

void Scene::update() {
	
	camera.update();

	glClearColor(settings.bgColor[0], settings.bgColor[1], settings.bgColor[2], 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	mat4 MVP;
	
	View = camera.getView();
	
	mat4 PlaneModel;
	MVP = Projection * View * PlaneModel;
	glUniformMatrix4fv(shaders.mvpId, 1, GL_FALSE, &MVP[0][0]);
	glUniform3f(shaders.colorId, 1.0, 1.0, 1.0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, planeVerticesBuffer);
	glVertexAttribPointer(shaders.vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
	glDrawArrays(GL_TRIANGLES, 0, 2 * 3);
	
	// 1rst attribute buffer : vertices
	// glEnableVertexAttribArray(0);
	// glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// glVertexAttribPointer(
	//    0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	//    3,                  // size
	//    GL_FLOAT,           // type
	//    GL_FALSE,           // normalized?
	//    0,                  // stride
	//    (void*)0            // array buffer offset
	// );
	 
	// // Draw the triangle !
	// glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	 
	// glDisableVertexAttribArray(0);
	
}

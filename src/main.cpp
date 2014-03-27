
#include "settings.h"
#include "userInterface.h"
#include "scene.h"


#include <GL/glew.h>
#include <GL/glfw.h>
#include <iostream>

using namespace std;

int init();

int main(int argc, char ** args) {
	if(init() != 0)
		return 1;
	
	Settings settings;
	// UserInterface ui(settings);
	Scene scene(settings);

	// ui.init();
	scene.init();
	
	/////////////////////////////////////////
	
	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};
	
	// This will identify our vertex buffer
	GLuint vertexbuffer;
	 
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	 
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	 
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	/////////////////////////////////////////

	
	while (glfwGetWindowParam(GLFW_OPENED) && !glfwGetKey(GLFW_KEY_ESC)) {
		scene.update();
		// ui.update();
		
		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		   3,                  // size
		   GL_FLOAT,           // type
		   GL_FALSE,           // normalized?
		   0,                  // stride
		   (void*)0            // array buffer offset
		);
		 
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		 
		glDisableVertexAttribArray(0);
		
		glfwSwapBuffers();
	}
	glfwTerminate();
	return 0;
}

int init() {
	if (!glfwInit()) {
		cerr << "Failed to initialize GLFW" << endl;
		return 1;
	}

	if (!glfwOpenWindow(500, 500, 50, 50, 50, 50, 32, 0, GLFW_WINDOW)) {
		cerr << "Failed to open GLFW window." << endl;
		glfwTerminate();
		return 2;
	}
	
	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW" << endl;
		return 3;
	}
	
	glfwSetWindowTitle("Rabbit Demo");
	glfwEnable(GLFW_STICKY_KEYS);
	
	return 0;
}
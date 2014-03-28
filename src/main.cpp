#include "scene.h"
#include "settings.h"
#include "userInterface.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace glm;
using namespace std;

GLFWwindow* window;

int main() {
	if(!glfwInit()) {
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(500, 500, "Rabbit demo", NULL, NULL);
	if(window == NULL) {
		cout << "failed to open window" << endl;
		glfwTerminate();
		return 1;
	}
	
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	
	Settings settings;
	Scene scene(settings);
	UserInterface ui(window, settings);	
	scene.init();
	ui.init();

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0) {
		scene.update();
		ui.update();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	scene.terminate();
	glfwTerminate();

	return 0;
}


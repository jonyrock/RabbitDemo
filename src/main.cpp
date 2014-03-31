#include <GL/glew.h>
#include <glm/glm.hpp>

#include "GLFW/glfw3.h"

#include "scene.h"
#include "settings.h"
#include "userInterface.h"

#include <iostream>

using namespace glm;
using namespace std;

GLFWwindow* window;

int main() {
		
	if(!glfwInit()) {
		cerr << "Failed to initialize GLFW" << endl;
		return -1;
	}

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(700, 500, "Rabbit demo", NULL, NULL);
	if(window == NULL) {
		cout << "failed to open window" << endl;
		glfwTerminate();
		return 1;
	}
	
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW" << endl;
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


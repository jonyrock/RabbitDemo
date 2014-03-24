
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
	UserInterface ui(settings);
	Scene scene(settings);
	ui.init();
	scene.init();
	
	while (glfwGetWindowParam(GLFW_OPENED) && !glfwGetKey(GLFW_KEY_ESC)) {
		scene.update();
		ui.update();
		glfwSwapBuffers();
	}
	
	glfwTerminate();
	
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
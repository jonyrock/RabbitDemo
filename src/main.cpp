
#include "AntTweakBar.h"

#include <GL/glew.h>
#include <GL/glfw.h>

#include <iostream>

using namespace std;

int GLinit();

int main(int argc, char ** args) {
	
	GLinit();
	
	TwInit(TW_OPENGL_CORE, NULL);
	
	TwBar *myBar;
	myBar = TwNewBar("NameOfMyTweakBar");

}


int GLinit() {

	if (!glfwInit()) {
		cerr << "Failed to initialize GLFW" << endl;
		return -1;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);

	if (!glfwOpenWindow(1024, 768, 0, 0, 0, 0, 32, 0, GLFW_WINDOW)) {
		cerr << "Failed to open GLFW window." << endl;
		glfwTerminate();
		return -1;
	}
	
	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW" << endl;
		return -1;
	}

	glfwSetWindowTitle("Geometry party");
	glfwEnable(GLFW_STICKY_KEYS);

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_LESS);

	return 0;

}
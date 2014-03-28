#pragma once

#include "settings.h"
#include "AntTweakBar.h"

#include <GLFW/glfw3.h>

class UserInterface {
	GLFWwindow* window;
	Settings& settings;
public:
	UserInterface(GLFWwindow* window, Settings& settings): 
		window(window),
		settings(settings) {
	}
	void init();
	void update();
	
private:
	TwBar* bar;
	void addLightTypes();
	void addFillTypes();
	void bindGLWF2Ant();
};
#pragma once

#include "settings.h"
#include "AntTweakBar.h"

#include <GLFW/glfw3.h>

class UserInterface {
	Settings& settings;
public:
	UserInterface(Settings& settings): 
		settings(settings){
		bar = NULL;
	}
	void init();
	void update();
	
private:
	TwBar* bar;
	void addLightTypes();
	void addFillTypes();
	void bindGLWF2Ant();
};

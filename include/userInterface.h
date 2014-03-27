#pragma once

#include "settings.h"
#include "AntTweakBar.h"

class UserInterface {
	Settings& settings;
public:
	UserInterface(Settings& settings): settings(settings) {
	}
	void init();
	void update();
	
private:
	TwBar* bar;
	void addLightTypes();
	void addFillTypes();
};
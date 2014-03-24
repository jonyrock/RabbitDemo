#pragma once


#include "settings.h"

class Scene {
	const Settings& settings;
public:
	Scene(const Settings& settings): settings(settings) {
	}
	void init();
	void update();
};
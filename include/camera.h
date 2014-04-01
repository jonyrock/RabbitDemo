#pragma once
#include "settings.h"

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>


class Camera {
private:

	const Settings& settings;
	glm::vec3 _cameraPosition;

public:

	Camera(const Settings& settings, glm::vec3 cameraPosition)
			: settings(settings), _cameraPosition(cameraPosition) {

	}

	glm::mat4 getView();

	void zoom(float scale);
	void update();
	void init();

};

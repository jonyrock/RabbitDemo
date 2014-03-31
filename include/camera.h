#pragma once
#include "settings.h"

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>


class Camera {
private:

	const Settings& settings;

	glm::vec3 _cameraPosition;
	int _xBefore;
	int _yBefore;
	int _wheelBefore;
	float _heading;
	float _pitch;

	void init();

public:

	Camera(const Settings& settings, glm::vec3 cameraPosition)
			: settings(settings), _cameraPosition(cameraPosition) {
		_xBefore = 0;
		_yBefore = 0;
		_wheelBefore = 0;
		_heading = 0;
		_pitch = 0;
		
	}

	glm::mat4 getView();

	inline void rotateX(int deg) {
		if (deg == 0)
			return;
		_pitch += deg / 5.0f;
	}

	inline void rotateY(int deg) {
		if (deg == 0)
			return;
		_heading += deg / 5.0f;
	}

	void zoom(float scale);
	void update();

};

#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

enum LightType {
	LT_PHONG = 1, LT_BLINN_PHONG = 2
};

enum FillType {
	FT_FLAT = 1, FT_PER_VERTEX = 2, FT_PER_FRAGMENT = 3
};

struct Settings {

	GLFWwindow* window;

	float ambient;
	float diffuse;
	float specular;
	float specularPower;
	LightType lightType;
	FillType fillType;

	float bgColor[3];
	float planeColor[3];
	float rabbitColor[3];
	float lightColor[3];

	float lightPosition[3];

	double cursorXPos;
	double cursorYPos;

	bool mouseLeftButtonIsPressed;

	float kc;
	float kl;
	float kq;

	Settings(GLFWwindow* window)
			: window(window) {

		ambient = 0.3f;
		diffuse = 0.5f;
		specular = 0.6f;
		specularPower = 19.0f;
		kc = 1.0f;
		kl = 0.000001f;
		kq = 0.0000000001f;

		lightType = LT_PHONG;
		fillType = FT_FLAT;

		bgColor[0] = 0.1f;
		bgColor[1] = 0.2f;
		bgColor[2] = 0.4f;

		planeColor[0] = 0.9f;
		planeColor[1] = 0.9f;
		planeColor[2] = 0.9f;

		rabbitColor[0] = 0.9f;
		rabbitColor[1] = 0.3f;
		rabbitColor[2] = 0.3f;

		lightColor[0] = 1.0f;
		lightColor[1] = 0.98f;
		lightColor[2] = 0.9f;

		lightPosition[0] = 30.0f;
		lightPosition[1] = 30.0f;
		lightPosition[2] = 20.0f;

		cursorXPos = 0;
		cursorYPos = 0;

		mouseLeftButtonIsPressed = false;

	}

	inline glm::vec3 getBgColor() const {
		return glm::vec3(bgColor[0], bgColor[1], bgColor[2]);
	}

	inline glm::vec3 getPlaneColor() const {
		return glm::vec3(planeColor[0], planeColor[1], planeColor[2]);
	}

	inline glm::vec3 getRabbitColor() const {
		return glm::vec3(rabbitColor[0], rabbitColor[1], rabbitColor[2]);
	}

};


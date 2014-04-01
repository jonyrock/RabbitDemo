#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

enum LightType {
	LT_PHONG, LT_BLINN_PHONG
};

enum FillType {
	FT_FLAT, FT_PER_VERTEX, FT_PER_FRAGMENT
};

struct Settings {
	float ambient;
	float diffuse;
	float specular;
	float specularPower;
	LightType lightType;
	FillType fillType;

	float bgColor[3];
	float planeColor[3];
	float rabbitColor[3];
	
	double cursorXPos;
	double cursorYPos;
	
	bool mouseLeftButtonIsPressed;

	GLFWwindow* window;

	Settings(GLFWwindow* window)
			: window(window) {

		ambient = 0.5;
		diffuse = 0.5;
		specular = 1.0;
		specularPower = 1.5;
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


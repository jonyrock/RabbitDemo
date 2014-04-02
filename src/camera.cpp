#include "camera.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include "tools.h"

using namespace std;
using namespace glm;

static Camera* me;

static bool wIsPressed = false;
static bool sIsPressed = false;

static float heading = 0;
static float pitch = 0;

static void rotateX(int deg) {
	if (deg == 0)
		return;
	pitch += deg / 5.0f;
}

static void rotateY(int deg) {
	if (deg == 0)
		return;
	heading += deg / 5.0f;
}

void onKey(GLFWwindow* window, int key, int, int action, int) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_W) {
			wIsPressed = true;
		}
		if (key == GLFW_KEY_S) {
			sIsPressed = true;
		}
	}
	if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_W) {
			wIsPressed = false;
		}
		if (key == GLFW_KEY_S) {
			sIsPressed = false;
		}
	}

}

void onScroll(GLFWwindow * window, double xoffset, double yoffset) {
	me->zoom(-yoffset);
}

void Camera::init() {
	me = this;
	glfwSetKeyCallback(settings.window, onKey);
	glfwSetScrollCallback(settings.window, onScroll);
}

static int cursorPosXBefore = 0;
static int cursorPosYBefore = 0;

void Camera::update() {

	if (glfwGetKey(settings.window, 'W') == GLFW_PRESS) {
		zoom(-0.01);
	}

	if (glfwGetKey(settings.window, 'S') == GLFW_PRESS) {
		zoom(0.01);
	}

	int xDiff = settings.cursorXPos - cursorPosXBefore;
	int yDiff = settings.cursorYPos - cursorPosYBefore;

	cursorPosXBefore = settings.cursorXPos;
	cursorPosYBefore = settings.cursorYPos;

	if (settings.mouseLeftButtonIsPressed) {
		rotateX(-xDiff);
		rotateY(-yDiff);
	}

}

void Camera::zoom(float scale = 1) {
	if (scale == 0)
		return;
	vec3 uv = normalize(_cameraPosition);
	float magnitude = dot(_cameraPosition, _cameraPosition);
	if (magnitude + scale < 0)
		return;
	uv *= scale;
	_cameraPosition += uv;
}

mat4 Camera::getView() {
	mat4 view = lookAt(_cameraPosition, vec3(0, 0, 0), vec3(0, 1, 0));
	view = view * rotate(mat4(1.0f), -heading, vec3(1, 0, 0));
	view = view * rotate(mat4(1.0f), -pitch, vec3(0, 1, 0));
	return view;
}

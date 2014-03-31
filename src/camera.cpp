#include "camera.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

using namespace std;
using namespace glm;

void Camera::init() {
//	glfwSetMouseButtonCallback(wondow, );
}

void Camera::update() {

//	if (glfwGetKey(settings.window, 'W') == GLFW_PRESS) {
//		zoom(-0.3);
//	}
//
//	cout << glfwGetKey(settings.window, 'W') << endl;
//
//	if (glfwGetKey(settings.window, 'S') == GLFW_PRESS) {
//		zoom(0.3);
//	}
//
//	int myX = 0;
//	int myY = 0;
////	glfwGetMousePos(window,&myX, &myY);
//	int xDiff = myX - _xBefore;
//	int yDiff = myY - _yBefore;
//	_xBefore = myX;
//	_yBefore = myY;

//	if (glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
//		rotateX(-xDiff);
//		rotateY(-yDiff);
//	}

//	int myWheel = glfwGetMouseWheel();
//	int wheelDiff = myWheel - _wheelBefore;
//	zoom(-wheelDiff);
//	_wheelBefore = myWheel;

}

void Camera::zoom(float scale = 1) {
	if (scale == 0)
		return;
	vec3 uv = glm::normalize(_cameraPosition);
	float magnitude = dot(_cameraPosition, _cameraPosition);
	if (magnitude + scale < 0)
		return;
	uv *= scale;
	_cameraPosition += uv;
}

mat4 Camera::getView() {
	mat4 view = lookAt(_cameraPosition, vec3(0, 0, 0), vec3(0, 1, 0));
	view = view * rotate(mat4(1.0f), -_heading, vec3(1, 0, 0));
	view = view * rotate(mat4(1.0f), -_pitch, vec3(0, 1, 0));
	return view;
}

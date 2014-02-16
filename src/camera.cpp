
#include "camera.h"

#include "GL/glfw.h"

void Camera::windowsIterate() {

    if (glfwGetKey('W') == GLFW_PRESS) {
        zoom(-0.3);
    }

    if (glfwGetKey('S') == GLFW_PRESS) {
        zoom(0.3);
    }

    int myX = 0;
    int myY = 0;
    glfwGetMousePos(&myX, &myY);
    int xDiff = myX - _xBefore;
    int yDiff = myY - _yBefore;
    _xBefore = myX;
    _yBefore = myY;

    if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        rotateX(-xDiff);
        rotateY(-yDiff);
    }

    int myWheel = glfwGetMouseWheel();
    int wheelDiff = myWheel - _wheelBefore;
    zoom(-wheelDiff);
    _wheelBefore = myWheel;

}
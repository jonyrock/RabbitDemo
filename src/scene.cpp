#include "scene.h"
#include <GL/glew.h>

void Scene::init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void Scene::update() {
	glClearColor(settings.bgColor[0], settings.bgColor[1], settings.bgColor[2], 1);
	glClear(GL_COLOR_BUFFER_BIT);
}
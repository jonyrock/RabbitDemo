#include "userInterface.h"
#include "settings.h"

#include "GLFW/glfw3.h"
#include "AntTweakBar.h"

static Settings* staic_settings;

void UserInterface::addLightTypes() {
	TwEnumVal types[] = { { LT_PHONG, "phong" },
			{ LT_BLINN_PHONG, "blinn phong" } };
	TwType twType = TwDefineEnum("", types, 2);
	TwAddVarRW(bar, "Light type", twType, &settings.lightType, NULL);
}

void UserInterface::addFillTypes() {
	TwEnumVal types[] = { { FT_FLAT, "flat" }, { FT_PER_VERTEX, "per vertex" },
			{ FT_PER_FRAGMENT, "per fragment" } };
	TwType twType = TwDefineEnum("", types, 3);
	TwAddVarRW(bar, "Fill type", twType, &settings.fillType, NULL);
}

void UserInterface::init() {

	TwInit(TW_OPENGL, NULL);

	staic_settings = &settings;

	int glfwWindowWidth = 0, glfwWindowHeight = 0;
	glfwGetWindowSize(settings.window, &glfwWindowWidth, &glfwWindowHeight);
	TwWindowSize(glfwWindowHeight, glfwWindowHeight);
	bindGLWF2Ant();

	bar = TwNewBar("Settings");
	addLightTypes();
	addFillTypes();

	TwAddVarRW(bar, "ambient", TW_TYPE_FLOAT, &settings.ambient,
		"label='Ambient' ");
	TwAddVarRW(bar, "diffuse", TW_TYPE_FLOAT, &settings.diffuse,
		"label='Diffuse' ");
	TwAddVarRW(bar, "specular", TW_TYPE_FLOAT, &settings.specular,
		"label='Specular' ");
	TwAddVarRW(bar, "specularPower", TW_TYPE_FLOAT, &settings.specularPower,
		"label='Specular power' ");
	TwAddVarRW(bar, "bgColor", TW_TYPE_COLOR3F, &settings.bgColor,
		"label='Background color' ");
	TwAddVarRW(bar, "planeColor", TW_TYPE_COLOR3F, &settings.planeColor,
		"label='Plane color' ");
	TwAddVarRW(bar, "rabbitColor", TW_TYPE_COLOR3F, &settings.rabbitColor,
		"label='Rabbit color' ");
}

void UserInterface::update() {
	TwDraw();
}

// Bind GLWF events to AntTweakBar

static void onGlfwSetWindowSize(GLFWwindow * window, int width, int height) {
	TwWindowSize(width, height);
}

static void onGlfwSetMouseButton(GLFWwindow * window, int button, int action,
	int mods) {
	TwEventMouseButtonGLFW(button, action);
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		staic_settings->mouseLeftButtonIsPressed = action == GLFW_PRESS;
	}
}

static void onGlfwSetCursorPos(GLFWwindow * window, double xpos, double ypos) {
	TwEventMousePosGLFW(xpos, ypos);
	staic_settings->cursorXPos = xpos;
	staic_settings->cursorYPos = ypos;
}

void UserInterface::bindGLWF2Ant() {
	glfwSetWindowSizeCallback(settings.window, &onGlfwSetWindowSize);
	glfwSetMouseButtonCallback(settings.window, &onGlfwSetMouseButton);
	glfwSetCursorPosCallback(settings.window, &onGlfwSetCursorPos);
}


#pragma once

// TODO: remove ol glfw
#include <GL/glfw.h>

#include <glm/glm.hpp>
#include <vector>

void fillPlaneUV(std::vector<glm::vec2>& vertices);
void fillCubeUV(std::vector<glm::vec2>& vertices);
void fillSphereUV(std::vector<glm::vec2>& vertices);



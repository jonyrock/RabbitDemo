#pragma once

// TODO: remove ol glfw
#include <GL/glfw.h> 

#include <glm/glm.hpp>
#include <vector>

void fillCube(std::vector<glm::vec3>& vertices);
void fillPlane(std::vector<glm::vec3>& vertices);
void fillSphere(std::vector<glm::vec3>& vertices);



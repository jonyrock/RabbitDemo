
#include "figures.h"

using namespace std;
using namespace glm;

void fillCube(std::vector<glm::vec3>& vertices) {
    vertices.push_back(vec3(-1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, -1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(-1.0f, 1.0f, 1.0f));
    vertices.push_back(vec3(1.0f, -1.0f, 1.0f));
}


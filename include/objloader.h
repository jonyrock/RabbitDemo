#pragma once

#include <glm/glm.hpp>
#include <vector>

bool loadOBJ(
	const char* path,
	std::vector<glm::vec3>& out_vertices,
	std::vector<glm::vec3>& out_normals
);

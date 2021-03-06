#pragma once

#include <iostream>
#include <glm/glm.hpp>

inline std::ostream& operator<<(std::ostream& ostr, glm::vec3 v) {
	ostr << "vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return ostr;
}

inline std::ostream& operator<<(std::ostream& ostr, glm::vec4 v) {
	ostr << "vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
	return ostr;
}

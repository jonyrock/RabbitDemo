#pragma once

#include <iostream>

#include <glm/glm.hpp>

using namespace std;
using namespace glm;

inline ostream& operator<<(ostream& ostr, vec3 v) {
	ostr << "vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return ostr;
}

inline ostream& operator<<(ostream& ostr, vec4 v) {
	ostr << "vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
	return ostr;
}
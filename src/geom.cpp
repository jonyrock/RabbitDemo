#include "geom.h"
#include <vector>

#include <math.h>
#include <iostream>

#include <glm/gtx/rotate_vector.hpp> 

#include <iostream>

#include <glm/glm.hpp>

using namespace std;
using namespace glm;

void fillPlane(vector<vec3>& vertices) {

	vertices.push_back(vec3(-1, -1, 0));
	vertices.push_back(vec3(1, 1, 0));
	vertices.push_back(vec3(-1, 1, 0));

	vertices.push_back(vec3(-1, -1, 0));
	vertices.push_back(vec3(1, -1, 0));
	vertices.push_back(vec3(1, 1, 0));

}

void fillCube(vector<vec3>& vertices) {

	vertices = {
		vec3(-1, -1, 1),
		vec3(1, 1, 1),
		vec3(-1, 1, 1),

		vec3(-1, -1, 1),
		vec3(1, -1, 1),
		vec3(1, 1, 1),

		vec3(-1, -1, -1),
		vec3(1, 1, -1),
		vec3(-1, 1, -1),

		vec3(-1, -1, -1),
		vec3(1, -1, -1),
		vec3(1, 1, -1),

		vec3(-1, 1, 1),
		vec3(1, 1, -1),
		vec3(-1, 1, -1),

		vec3(-1, 1, 1),
		vec3(1, 1, 1),
		vec3(1, 1, -1),

		vec3(-1, -1, 1),
		vec3(1, -1, -1),
		vec3(-1, -1, -1),

		vec3(-1, -1, 1),
		vec3(1, -1, 1),
		vec3(1, -1, -1),

		vec3(1, -1, 1),
		vec3(1, 1, -1),
		vec3(1, 1, 1),

		vec3(1, -1, 1),
		vec3(1, -1, -1),
		vec3(1, 1, -1),

		vec3(-1, -1, 1),
		vec3(-1, 1, -1),
		vec3(-1, 1, 1),

		vec3(-1, -1, 1),
		vec3(-1, -1, -1),
		vec3(-1, 1, -1)
	};

}

void fillSphere(vector<vec3>& vertices) {

	float step = 1;

	for (float beta = 0; beta < 360; beta += step) {
		for (float alpha = -90; alpha < 90; alpha += step) {

			/***********
			 * b -----c
			 * |      |
			 * |      |
			 * a ---- d
			 * ********/

			vec3 a = rotateY(rotateZ(vec3(1, 0, 0), alpha), beta);
			vec3 b = rotateY(rotateZ(vec3(1, 0, 0), alpha + step), beta);
			vec3 c = rotateY(rotateZ(vec3(1, 0, 0), alpha + step), beta + step);
			vec3 d = rotateY(rotateZ(vec3(1, 0, 0), alpha), beta + step);

			vertices.push_back(a);
			vertices.push_back(c);
			vertices.push_back(b);

			vertices.push_back(a);
			vertices.push_back(d);
			vertices.push_back(c);

		}

	}

}


#include "figures/textures.h"

#include <iostream>

using namespace std;
using namespace glm;

void fillPlaneUV(std::vector<glm::vec2>& vertices) {

    vertices = {
        vec2(1, 0),
        vec2(0, 1),
        vec2(0, 0),

        vec2(1, 0),
        vec2(1, 1),
        vec2(0, 1)
    };

}

void fillCubeUV(std::vector<glm::vec2>& vertices) {

    for (int i = 0; i <= 6; i++) {
        vertices.push_back(vec2(1, 0));
        vertices.push_back(vec2(0, 1));
        vertices.push_back(vec2(0, 0));

        vertices.push_back(vec2(1, 0));
        vertices.push_back(vec2(1, 1));
        vertices.push_back(vec2(0, 1));
    }

}

void fillSphereUV(std::vector<glm::vec2>& vertices) {

    //    cout << "fill sphere" << endl;

    float step = 1;

    for (float beta = 0; beta < 360; beta += step) {
        for (float alpha = -90; alpha < 90; alpha += step) {

            /***********
             * b ---- c
             * |      |
             * |      |
             * a ---- d
             * ********/

            float x = beta / 360.0f;
            float y = (alpha + 90.0f) / 180.0f;

            float offsetX = step / 360.0f;
            float offsetY = step / 180.0f;

            vec2 a(x, y);
            vec2 b(x,y + offsetY);
            vec2 c(x + offsetX, y + offsetY );
            vec2 d(x + offsetX, y);
            
            vertices.push_back(a);
            vertices.push_back(c);
            vertices.push_back(b);

            vertices.push_back(a);
            vertices.push_back(d);
            vertices.push_back(c);
            
        }

    }
}


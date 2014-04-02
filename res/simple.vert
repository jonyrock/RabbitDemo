#version 130

uniform vec3 color;

in vec3 vertexPosition_modelspace;
in vec3 vertexNormal_modelspace;

out vec3 vertexColor;
out vec3 vertexNormal;
out vec3 vertexPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform int fillType;

#include "res/modelView.glsl"
#include "res/computeLight.glsl"

void main() {
    gl_Position = 
    	projection *
    	view * 
    	model *
    	vec4(vertexPosition_modelspace, 0.3);
    vertexColor = color;
    vertexNormal = normalize(mv(vertexNormal_modelspace));
    vertexPosition = mv(vertexPosition_modelspace);
    if(lightType == 3) {
    	return;
    }
    vertexColor = computeLight(
    	vertexColor, vertexPosition, vertexNormal	
    );
}


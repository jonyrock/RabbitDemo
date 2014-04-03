#version 130

uniform vec3 color;

in vec3 vertexPosition_modelspace;
in vec3 vertexNormal_modelspace;
in vec3 flatPosition;
in vec3 flatNormal;

out vec3 vertexColor;
out vec3 vertexNormal;
out vec3 vertexPosition;

flat out vec3 flatColor;

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
    
    vertexNormal = mv(vertexNormal_modelspace);
    vertexPosition = mv(vertexPosition_modelspace);
    
	if(fillType == 1) {
		flatColor = computeLight(
    		color, mv(flatPosition), mv(flatPosition)
    	);
	}
	
	if(fillType == 2) {
		vertexColor = computeLight(
    		color, vertexPosition, vertexNormal
    	);
	}
	
	if(fillType == 3) {
		vertexColor = color;
	}
	
}


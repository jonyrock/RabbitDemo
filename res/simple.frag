#version 130

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Interpolated values from the vertex shaders
in vec3 vertexColor;
in vec3 vertexNormal;
in vec3 vertexPosition;

flat in vec3 flatColor;

uniform int fillType;

out vec3 color;

#include "res/computeLight.glsl"

void main() {
	   	
	if(fillType == 1) {
		color = flatColor;
	}

    if(fillType == 2) {
    	color = vertexColor;
    }
    
    if(fillType == 3) {
    	color = computeLight(
    		vertexColor, vertexPosition, vertexNormal
    	);
    } 
    
}
#version 130

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Interpolated values from the vertex shaders
in vec3 vertexColor;
in vec3 vertexNormal;
in vec3 vertexPosition;

uniform int fillType;

out vec3 color;

#include "res/computeLight.glsl"

void main() {
        
    if(fillType == 2) {
    	color = vertexColor;
    	return;
    }
    
    color = computeLight(
    	vertexColor, vertexPosition, vertexNormal
    );

}
#version 130

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 color;

in vec3 vertexPosition_modelspace;

out vec3 vertColor;

void main() {
    gl_Position = 
    	projection *
    	view * 
    	model *
    	vec4(vertexPosition_modelspace, 0.3);
    vertColor = color;
}


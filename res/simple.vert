#version 130

uniform float ambient;
uniform float diffuse;
uniform float specular;
uniform float specularPower;
uniform vec3  viewerPos;

uniform int lightType;
uniform int fillType;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 color;

in vec3 vertexPosition_modelspace;
in vec3 vertexNormal_modelspace;

out vec3 vertexColor;
out vec3 vertexNormal;
out vec3 vertexPosition;

void main() {
    gl_Position = 
    	projection *
    	view * 
    	model *
    	vec4(vertexPosition_modelspace, 0.3);
    
    vertexColor = color;
    vertexNormal = normalize((view * model * vec4(vertexNormal_modelspace,1)).xyz);
    vertexPosition = (view * model * vec4(vertexPosition_modelspace,1)).xyz;
}


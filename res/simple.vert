#version 130

in vec3 vertexPosition_modelspace;

uniform mat4 MVP;
uniform vec3 vertexColor;
uniform float ambient;
uniform float diffuse;

out vec3 color;
out vec3 fragmentColor;

void main() {
    gl_Position   = MVP * vec4(vertexPosition_modelspace, 1);
    fragmentColor = vertexColor;
}


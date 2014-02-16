#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;

// Output data ; will be interpolated for each fragment.
out vec3 color;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform vec3 vertexColor;
uniform float ambient;
uniform float diffuse;

out vec3 fragmentColor;

void main() {
    gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);
    fragmentColor = vertexColor;
}


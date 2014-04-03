#include <GL/glew.h>
#include <glm/glm.hpp>

#include "shaders.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <stdlib.h>
#include <string.h>

#include <sstream>

#include <stdexcept>
#include <set>

using namespace std;
using namespace glm;

void Shaders::init() {
	programId = loadShaders("res/simple.vert", "res/simple.frag");
	if (programId == 0)
		exit(1);

	modelId = glGetUniformLocation(programId, "model");
	viewId = glGetUniformLocation(programId, "view");
	projectionId = glGetUniformLocation(programId, "projection");
	colorId = glGetUniformLocation(programId, "color");
	lightColorId = glGetUniformLocation(programId, "lightColor");
	lightPositionId = glGetUniformLocation(programId, "lightPosition");

	vertexPosition_modelspaceId = glGetAttribLocation(programId,
		"vertexPosition_modelspace");
	vertexNormal_modelspaceId = glGetAttribLocation(programId,
		"vertexNormal_modelspace");
	
	flatPositionId = glGetAttribLocation(programId, "flatPosition");
	flatNormalId = glGetAttribLocation(programId, "flatNormal");

	lightTypeId = glGetUniformLocation(programId, "lightType");
	fillTypeId = glGetUniformLocation(programId, "fillType");

	ambientId = glGetUniformLocation(programId, "ambient");
	diffuseId = glGetUniformLocation(programId, "diffuse");
	specularId = glGetUniformLocation(programId, "specular");
	specularPowerId = glGetUniformLocation(programId, "specularPower");

	kcId = glGetUniformLocation(programId, "kc");
	klId = glGetUniformLocation(programId, "kl");
	kqId = glGetUniformLocation(programId, "kq");

	glUseProgram(programId);
}

void Shaders::setColor(vec3 color) {
	glUniform3f(colorId, color[0], color[1], color[2]);
}
void Shaders::setModel(mat4 mat) {
	glUniformMatrix4fv(modelId, 1, GL_FALSE, &mat[0][0]);
}
void Shaders::setView(mat4 mat) {
	glUniformMatrix4fv(viewId, 1, GL_FALSE, &mat[0][0]);
}
void Shaders::setProjection(mat4 mat) {
	glUniformMatrix4fv(projectionId, 1, GL_FALSE, &mat[0][0]);
}

void Shaders::update() {

	glUniform3f(lightColorId, settings.lightColor[0], settings.lightColor[1],
		settings.lightColor[2]);
	glUniform3f(lightPositionId, settings.lightPosition[0],
		settings.lightPosition[1], settings.lightPosition[2]);

	glUniform1i(lightTypeId, settings.lightType);
	glUniform1i(fillTypeId, settings.fillType);

	glUniform1f(ambientId, settings.ambient);
	glUniform1f(diffuseId, settings.diffuse);
	glUniform1f(specularId, settings.specular);
	glUniform1f(specularPowerId, settings.specularPower);

	glUniform1f(kcId, settings.kc);
	glUniform1f(klId, settings.kl);
	glUniform1f(kqId, settings.kq);

}

void loadCode(const string& path, stringstream& stream, set<string>& included) {

	if (included.find(path) != included.end())
		return;

	included.insert(path);

	ifstream str;
	str.open(path);
	string line;

	if (!str.is_open()) {
		throw logic_error("Can't open file " + path);
	}

	while (getline(str, line)) {
		stringstream ss(line);
		string a;
		ss >> a;
		if (a == "#include") {
			string innerPath;
			ss >> innerPath;
			loadCode(innerPath.substr(1, innerPath.length() - 2), stream,
				included);
			stream << endl;
		} else {
			stream << line << endl;
		}
	}

}

string loadCode(const string& path) {
	stringstream ss;
	set<string> included;
	loadCode(path, ss, included);
	return ss.str();
}

GLuint Shaders::loadShaders(const char * vertex_file_path,
	const char * fragment_file_path) {

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file

	string VertexShaderCode = loadCode(vertex_file_path);

	// Read the Fragment Shader code from the file
	string FragmentShaderCode = loadCode(fragment_file_path) + "\n";

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL,
			&VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL,
			&FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL,
			&ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;

}

Shaders::~Shaders() {
	glDeleteProgram(programId);
}


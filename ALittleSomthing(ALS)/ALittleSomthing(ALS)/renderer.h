#pragma once

#ifndef GLEW_INC
#define GLEW_INC
#include "opengl_stuff\headers\GL\glew.h"
#endif

#ifndef GLFW_INC
#define GLFW_INC
#include "opengl_stuff\headers\GLFW\glfw3.h"
#endif 

#ifndef ERROR_INC
#define ERROR_INC
#include "error.h"
#endif // !ERROR_INC

#ifndef IFSTREAM_INC
#define IFSTREAM_INC
#include <fstream>
#endif // !IFSTREAM_INC

#ifndef VECTOR_INC
#define VECTOR_INC
#include <vector>
#endif // !VECTOR_INC


class renderer
{
public:

	GLFWwindow* window;
	bool* shallEnd;
	GLuint VertexShader;
	GLuint FragmentShader;
	GLuint ShaderProgram;

	void startStuff();
	void compileShader(const std::string& filePath, GLuint id);
	void render();
	renderer(bool* SeV);
	~renderer();
};


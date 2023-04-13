#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{

	ifstream vertexFile;
	ifstream fragmentFile;

	stringstream vertexSStream, fragmentSStream;

	vertexFile.open(vertexPath);
	fragmentFile.open(fragmentPath);

	// 保证ifstream对象可以抛出异常：
	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragmentFile.exceptions(ifstream::failbit || ifstream::badbit);

	try
	{
		if (!vertexFile.is_open() || !fragmentFile.is_open())
		{
			throw exception("error");
		}
		// 读取文件的缓冲内容到数据流中
		vertexSStream << vertexFile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();

		vertexString = vertexSStream.str();
		fragmentString = fragmentSStream.str();

		vertexSource = vertexString.c_str();
		fragmentSource = fragmentString.c_str();

		unsigned int vertex, fragment;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);

		checkComplieErrors(vertex, "VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);

		checkComplieErrors(fragment, "FRAGMENT");


		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		checkComplieErrors(ID, "PROGRAM");

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	catch (const std::exception& ex)
	{
		printf(ex.what());
	}
}

void Shader::use()
{
	glUseProgram(ID);
}
void Shader::checkComplieErrors(unsigned int ID, std::string type)
{
	int success;
	char infoLog[512];
	if (type != "PROGRAM")
	{
		glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(ID, 512, NULL, infoLog);
			cout << "shader complie error" << infoLog << endl;
		}


	}
	else
	{
		glGetShaderiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(ID, 512, NULL, infoLog);
			cout << "program linking error" << infoLog << endl;
		}
	}
}




















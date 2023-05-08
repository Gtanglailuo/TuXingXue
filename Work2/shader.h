#pragma once
#include<string>
#include<iostream>
using namespace std;
class Shader
{
public:

	Shader(const char* vertexPath, const char* fragmentPath);

	string vertexString;
	string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;
	unsigned int ID;
	void use();
	void checkComplieErrors(unsigned int ID, std::string type);



};

















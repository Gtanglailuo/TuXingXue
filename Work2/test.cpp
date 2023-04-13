#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 900;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


int main()
{
    
    #pragma region Open a Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 1080, 900);
    glEnable(GL_DEPTH_TEST);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#pragma endregion
    #pragma region Init Shader Program
    Shader* myShader = new Shader("vertexShaderSource.txt", "fragmentShaderSource.txt");
    #pragma endregion

    float vertices[] = {
    -0.1f, -0.1f, 0.0f,
     0.1f, -0.1f, 0.0f,
     0.0f,  0.1f, 0.0f
    };

    float vertices1[] = {
    -0.1f, -0.1f, 0.0f,
     0.1f, -0.1f, 0.0f,
     0.0f,  0.1f, 0.0f
    };
    unsigned int VBO,VB02, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(6);

    unsigned int VBO1, VAO1;
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    glBindVertexArray(VAO1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

    glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(6);
    //»ù±¾±ä»»´¦Àí
   
    unsigned int transIndex = glGetUniformLocation(myShader->ID, "trans");
   
    unsigned int transIndex1 = glGetUniformLocation(myShader->ID, "trans1");
  

    //mytrans = glm::scale(mytrans, glm::vec3(glm::abs(glm::sin((float)glfwGetTime() * 0.1f)), 1.0f, 1.0f));

    while (!glfwWindowShouldClose(window))
    {

        processInput(window);
        glm::mat4 mytrans = glm::mat4(1.0f);
        
        mytrans = glm::translate(mytrans, glm::vec3(0.8f * sin((float)glfwGetTime()), 0.8f * cos((float)glfwGetTime()),0.0f));
        mytrans = glm::rotate(mytrans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        mytrans = glm::scale(mytrans, glm::vec3(1.0f * sin(0.5 * (float)glfwGetTime()), 1.0f * sin(0.8 * (float)glfwGetTime()), 1.0f));
        
        // Çå¿ÕÆÁÄ»
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);

        myShader->use();

        glUniformMatrix4fv(transIndex,1,GL_FALSE,glm::value_ptr(mytrans));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

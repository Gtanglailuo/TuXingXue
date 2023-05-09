#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include <cmath>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
float lastX = 400, lastY = 300;
//摄像机
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f),
    glm::radians(0.0f),
    glm::radians(180.0f),
    glm::vec3(0.0f, 1.0f, 0.0f));
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow* window);
const unsigned int SCR_WIDTH = 1500;
const unsigned int SCR_HEIGHT = 1500;
int main()
{
#pragma region Open a Window

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 2500, 2500);


    //想启用深度测试(坐标系统)
    glEnable(GL_DEPTH_TEST);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#pragma endregion


#pragma region Init Shader Program

    Shader* myShader = new Shader("vertexShaderSource.txt", "fragmentShaderSource.txt");
#pragma endregion


#pragma region Init MVP

    //变换处理
    unsigned int transformLoc = glGetUniformLocation(myShader->ID, "transform");

    //坐标系统变换操作
    unsigned int modelLoc = glGetUniformLocation(myShader->ID, "model");
    unsigned int viewLoc = glGetUniformLocation(myShader->ID, "view");
    unsigned int projectionLoc = glGetUniformLocation(myShader->ID, "projection");

    //观察矩阵
    glm::mat4 view = glm::mat4(1.0f);
    //投影矩阵
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    unsigned int transIndex = glGetUniformLocation(myShader->ID, "trans");
#pragma endregion

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapInterval(1);
        processInput(window);

        view = camera.GetViewMatrix();

        // Clear Screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);

       /* glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);*/
        //使用shader
        myShader->use();






       
        glfwSwapBuffers(window);
        glfwPollEvents();
        camera.UpdateCameraFocus();
    }
    glfwTerminate();
    return 0;
}
bool firstMouse = true;
float speed = 0.1f;
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
        camera.Position.z += 1.0f * speed;
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        camera.Position.z -= 1.0f * speed;
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.Position.y -= 1.0f * speed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.Position.y += 1.0f * speed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.Position.x += 1.0f * speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.Position.x -= 1.0f * speed;

}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

    glViewport(0, 0, width, height);
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;

    }

    float xoffset = xpos - lastX;
    float yoffset = ypos - lastY;

    lastX = xpos;
    lastY = ypos;



    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    //camera.ChangeCamera(xoffset, yoffset);
    camera.ChangeCamera(yoffset, xoffset);//修改偏移量
}


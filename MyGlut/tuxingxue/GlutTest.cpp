#include<math.h>
#include<cstdio>
#include<cstdlib>
#define NDEBUG
#include <GL/glut.h>
const double PI = acos(-1);


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);// 清空画布
	//绘制手

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.4, 0.4);
	glVertex2f(-0.05f, -0.1f);
	glVertex2f(-0.05f, -0.3f);
	glVertex2f(-0.55f, -0.2f);
	glVertex2f(-0.45f, -0.35f);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.4, 0.3);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(0.05f, -0.3f);
	glVertex2f(0.55f, -0.2f);
	glVertex2f(0.45f, -0.35f);
	glEnd();
	glFlush();
	//画脚
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.1, 0.8);
	glVertex2f(-0.1f, -0.5f);
	glVertex2f(-0.2f, -0.3f);
	glVertex2f(-0.3f, -0.8f);
	glVertex2f(-0.1f, -0.8f);

	glEnd();
	glFlush();


	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.1, 0.8);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.2f, -0.3f);
	glVertex2f(0.3f, -0.8f);
	glVertex2f(0.1f, -0.8f);

	glEnd();
	glFlush();

	//绘制身体
	float R3 = 0.35f;
	float R4 = 0.5f;
	int n3 = 100;
	glBegin(GL_POLYGON);
	for (int i = 0; i < n3; i++)
	{
		glColor3f(0.2f, 0.4f, 0.3f);
		glVertex2f(R3 * cos(2 * PI * i / n3), R4 * sin(2 * PI * i / n3));
	}
	glEnd();
	glFlush();


    //画头

    float R2 = 0.5f;
    int n2 = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < n2; i++)
    {
        glColor3f(0.94118f, 0.93333f, 0.94118f);
        glVertex2f(R2 * cos(2 * PI * i / n2), R2 * sin(2 * PI * i / n2)+0.4f);
    }
    glEnd();
    glFlush();

    //画两只眼睛
    float R = 0.1f;
    int n = 80;
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(R*cos(2*PI*i/n)+0.35f,R*sin(2*PI*i/n)+0.5f);      
    }
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(R * cos(2 * PI * i / n) - 0.35f, R * sin(2 * PI * i / n) + 0.5f);
    }
    glEnd();
    glFlush();
	//画嘴巴
	glColor3f(0.f, 0.5f, 1.0f);           //设置颜色  

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.1, 0.8);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.0f, -0.1f);
	


	glEnd();
	glFlush();


}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World!");
    glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}
//
//#define NDEBUG
//#include <GL/glut.h>
//#include <math.h>
//const GLfloat R = 0.5f;
//const GLfloat Pi = 3.1415926536f;
//const int n = 1000;
//void DrawTorus()
//{
//    int num = n / 50;
//    for (int i = 0; i < num; i++)
//    {
//        glBegin(GL_QUAD_STRIP);
//        for (int j = 0; j <= num; j++)
//        {
//            for (int k = 1; k >= 0; k--)
//            {
//                double s = (i + k) % num + 0.5;
//                double t = j % num;
//                glNormal3f(cos(2 * Pi / num * s) * cos(2 * Pi / num * t), cos(2 * Pi / num * s) * sin(2 * Pi / num * t), sin(2 * Pi / num * s));
//                glVertex3f((1 + R * cos(2 * Pi / num * s)) * cos(2 * Pi / num * t), (1 + R * cos(2 * Pi / num * s)) * sin(2 * Pi / num * t), R * sin(2 * Pi / num * s));
//            }
//        }
//        glEnd();
//    }
//}
//int main(int argc, char* argv[])
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//    glutInitWindowPosition(100, 100);
//    glutInitWindowSize(400, 400);
//    glutCreateWindow("Hello World!");
//    glutDisplayFunc(&DrawTorus);
//    glutMainLoop();
//    return 0;
//}
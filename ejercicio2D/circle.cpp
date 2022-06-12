/******************************************************
Name: Eduardo Carrion

This code is the homework for creatings circles
to compile this code you need to link libraries
use g++ circles.cpp -lGL -lGLU -lglut -o circles

Circles have been created by using points and lines.
Use circleByPointsDisp or circleByLinesDisp to diplay
the circles by the way you need it.
 ******************************************************/
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define PI 3,14

void reshape(GLint w, GLint h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

void circleByPointsDisp(){
    int radius = 70;

    glClearColor(0.2,0.2,0.2,0.2);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1);
    glColor3f(0.5,0.5,1);
    glBegin(GL_POINTS);
        for (int i = 0; i < 124000; ++i) {
            glVertex2f(cos(i) * radius, sin(i) * radius);
        }
    glEnd();

    radius = 52;
    glColor3f(0.3,0.7,1);
    glBegin(GL_POINTS);
        for (int i = 0; i < 124000; ++i) {
            glVertex2f(cos(i) * radius, sin(i) * radius);
        }
    glEnd();
 
    glutSwapBuffers();
}

void circleByLinesDisp(){
    int radius = 70;

    glClearColor(0.5,0.5,0.5,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);
    glColor3f(1,1,0);
    glBegin(GL_LINES);
        for (int i = 0; i < 4; ++i) {
            glVertex2i(cos(i) * radius, sin(i) * radius);
        }
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Homework Draw a Circle");
    glutDisplayFunc(circleByPointsDisp);
    glutReshapeFunc(reshape);
    glutMainLoop(); 
    return 0;
}

//use -lGL -lGLU -lglut to link libraries
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void reshape(GLint w, GLint h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

void puntosDisp(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glBegin(GL_POINTS);
        glColor3f(1,1,0);
        glVertex2f(2.5, 5.7);

        glColor3f(1,0,0);
        glVertex3f(50, 40, 0);
    glEnd();
    glutSwapBuffers();
}

void lineasDisp(){
    glClearColor(0.5,0.5,0.5,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(1,1,0);
        glVertex2i(50, -50);
        glVertex2i(-45,45);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2i(-50,-50);
        glVertex2i(45,45);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv){
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Ejemplo 2D");
   glutDisplayFunc(lineasDisp);
   glutReshapeFunc(reshape);
  glutMainLoop(); 
    return 0;
}

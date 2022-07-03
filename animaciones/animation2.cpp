#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void reshape(GLsizei w, GLsizei h){
    if(h==0){
        h=1;
    }
    glViewport(0, 0, w, h);
}

void init(){
    glClearColor(0, 0, 0, 0);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
}

void display(){

}

void cubo(){
    glBegin(GL_QUADS);
        //Top
        glColor3f(0.9,0.8,0.7);
        glVertex3f(1,1,-1);
        glVertex3f(-1,1,-1);
        glVertex3f(-1,1,1);
        glVertex3f(1,1,1);
        //Bottom
        glColor3f(1,0.5,0);
        glVertex3f(1,-1,1);
        glVertex3f(-1,-1,1);
        glVertex3f(-1,-1,-1);
        glVertex3f(1,-1,-1);
        //Front
        glColor3f(0,0.4,1);
        glVertex3f(1,1,1);
        glVertex3f(-1,1,1);
        glVertex3f(-1,-1,1);
        glVertex3f(1,-1,1);
        //Back
        glColor3f(0.8,0.2,0.4);
        glVertex3f(1,-1,-1);
        glVertex3f(-1,-1,-1);
        glVertex3f(-1,1,-1);
        glVertex3f(1,1,-1);
        //Left
        glColor3f(0.9,0.8,0.2);
        glVertex3f(-1,1,1);
        glVertex3f(-1,1,-1);
        glVertex3f(-1,-1,-1);
        glVertex3f(-1,-1,1);
        //Right
        glColor3f(1,0.7,0.3);
        glVertex3f(1,1,1);
        glVertex3f(1,1,-1);
        glVertex3f(1,-1,-1);
        glVertex3f(1,-1,1);
    glEnd();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Animation sample");
    
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}

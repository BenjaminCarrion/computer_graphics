#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLfloat angle =0;
GLfloat angle1 =0;
GLfloat angle2 =0;
int tiempo= 10;

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
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
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

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(tiempo, timer, 0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 0, 1, 1);
    cubo();
    glPopMatrix();
    

    glPushMatrix();
    glTranslatef(-4, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(angle1, 1, 1, 1);
    cubo();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -1, 0);
    glScalef(0.8, 0.8, 0.8);
    glRotatef(angle2, 1, 1, 0);
    cubo();
    glPopMatrix();


    glFlush();
    angle+=0.2;
    angle1+=0.3;
    angle2+=0.5;
    glutSwapBuffers();

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

    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

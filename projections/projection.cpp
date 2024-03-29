#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

float valorY = 0, valorX = 0, valorZ=0;
GLfloat rotAngulo = 0;
int refreshRate = 5;


void init(){
    glClearColor(0.18f, 0.25f, 0.34f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void mover (int key, int, int){
    switch (key) {
        case GLUT_KEY_LEFT:
            valorX--;
            break;
        case GLUT_KEY_RIGHT:
            valorX++;
            break;
        case GLUT_KEY_UP:
            valorY++;
            break;
        case GLUT_KEY_DOWN:
            valorY--;
            break;
    }
}

void myTimer(int valor){
    glutPostRedisplay();
    glutTimerFunc(refreshRate, myTimer, 0);
}

void reshape(GLsizei w, GLsizei h){
    if(h==0){
        h=1;
    }
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h, 1.0f, 20.0f);
    glMatrixMode(GL_MODELVIEW);
}

void cubo(){
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);

    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);

    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);


    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);

    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);

    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glEnd();
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(valorX,valorY,-20,
              0,0,0,
              0,1,0);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9); 
    glBegin(GL_QUADS);
        glVertex3f(-5, -2, -10);
        glVertex3f(-5, -2, 10);
        glVertex3f(5, -2, 10);
        glVertex3f(5, -2, -10);
    glEnd();
    glPopMatrix();
    glFlush();

    glPushMatrix();
    glTranslatef(3,0,-7);
    glRotatef(rotAngulo, 1, 1, 0);
    glScalef(0.5, 0.5, 0.5); 
    cubo();
    glPopMatrix();
    glFlush();


    glPushMatrix();
    glTranslatef(-4,1,-9);
    glRotatef(rotAngulo, 1, 1, 0);
    glScalef(0.9,0.9,0.9);
    cubo();
    glPopMatrix();
    glFlush();

    glutSwapBuffers();
    rotAngulo+=0.15f;
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    /* Use single color buffer instead of a depth buffer */
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    /* Windows dimensions - width and height */
    glutInitWindowSize(900, 600);
    /* Location of window - screen coordinates */
    glutInitWindowPosition(100, 100);
    /* Sets the window object name */
    glutCreateWindow("Ejemplo camara");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutSpecialFunc(mover);
    init();
    glutTimerFunc(0, myTimer, 0);
    glutMainLoop();
    return 0;
}

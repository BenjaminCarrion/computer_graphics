#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

static bool isKey=false, ismouse=false;
static float posx=0;
static GLfloat spin =0;

void init(){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(GLsizei w, GLsizei h){
    if(h==0){
        h=1;
    }
    glViewport(0, 0, w, h);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0,  1, 0);
    glPushMatrix();
    if(isKey)
        glTranslatef(posx, 0, 0);
    if(ismouse)
        glRotatef(spin, 0, 0, 1);
    glutWireTeacup(4);
    glPopMatrix();
    glFlush();

    glutSwapBuffers();
}

void movLeft(){
    if(isKey){
        posx-=0.0005;
    }
    if(ismouse){
        spin-=0.05;
        if(spin<-360)
            spin+=360;
    }
    glutPostRedisplay();
}

void movRight(){
    if(isKey){
        posx+=0.0005;
    }
    glutPostRedisplay();
}

void movement(int key, int, int){
    switch (key) {
        case GLUT_KEY_LEFT:
            isKey=true;
            glutIdleFunc(movLeft);
            break;
        case GLUT_KEY_RIGHT:
            isKey=true;
            glutIdleFunc(movRight);
            break;
        default:
            break;
    }
}

void movementStop(int key, int, int){
    switch (key) {
        case GLUT_KEY_LEFT:
            isKey=false;
            glutIdleFunc(NULL);
            break;
        case GLUT_KEY_RIGHT:
            isKey=false;
            glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

void mouse(int button, int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN){
                ismouse=true;
                glutIdleFunc(movLeft);
            }else if(state==GLUT_UP){
                ismouse=false;
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    } 
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
    glutSpecialFunc(movement);
    glutSpecialUpFunc(movementStop);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
    
}

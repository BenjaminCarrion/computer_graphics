//use -lGL -lGLU -lglut to link libraries
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void reshape(GLint w, GLint h){
    glViewport(0, 0, w, h);
}

void init3D(){
    glClearColor(0.9, 0.8, 0.6, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1, 4, 100);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
}

void cubo(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.7, 0, 0);
    glRotatef(45, 1, 0, 0);

    glColor3f(0.1, 0.1, 0.1);
    glutSolidCube(1);

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ejemplos 3D");
    glutDisplayFunc(cubo);
    glutReshapeFunc(reshape);
    init3D();
    glutMainLoop();
    
    return 0;
}

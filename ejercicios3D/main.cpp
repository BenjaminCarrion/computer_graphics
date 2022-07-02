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
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 0, 0);
}

void prismas3d(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -6);
    glRotatef(180, 1, 0, 0);
    //glScalef(0.5 , 0.5, 0.5);

    glBegin(GL_TRIANGLES);

        //Frente
        glColor3f(0, 0, 1);
        glVertex3f(0, 1, 0);
        glColor3f(0, 1, 0);
        glVertex3f(-1, -1, 1);
        glColor3f(1, 0, 0);
        glVertex3f(1, -1, 1);

        //Derecha
        glColor3f(0, 0, 1);
        glVertex3f(0, 1, 0);
        glColor3f(0, 1, 0);
        glVertex3f(1, -1, 1);
        glColor3f(1, 0, 0);
        glVertex3f(1, -1, -1);

        //Atrás 
        glColor3f(0, 0, 1);
        glVertex3f(0, 1, 0);
        glColor3f(0, 1, 0);
        glVertex3f(1, -1, -1);
        glColor3f(1, 0, 0);
        glVertex3f(-1, -1, -1);

        //Izquierda 
        glColor3f(1, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, -1, 1);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ejemplos 3D");
    glutDisplayFunc(prismas3d);
    glutReshapeFunc(reshape);
    init3D();
    glutMainLoop();
    
    return 0;
}

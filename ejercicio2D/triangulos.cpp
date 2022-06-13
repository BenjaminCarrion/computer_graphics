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

void triangulos(){
   glClearColor(0.9,0.8,0.6,1);
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
      glColor4f(0.4, 0.6,0.7,1);
      //Triángulo 1
      glVertex2f(75, 80);
      glVertex2f(10, 0);
      glVertex2f(75, -80);
      
      //Triángulo 2
      glVertex2f(-75, 80);
      glVertex2f(-10, 0);
      glVertex2f(-75, -80);
      
   glEnd();
   glutSwapBuffers();

}


int main(int argc, char **argv){
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Ejemplos 2D y 3D");
   glutDisplayFunc(triangulos);
   glutReshapeFunc(reshape);
   glutMainLoop(); 
   return 0;
}

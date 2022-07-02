//use -lGL -lGLU -lglut to link libraries
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void reshape(GLint w, GLint h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

void triangulos(){
   glClearColor(0.9,0.8,0.6,1);
   glClear(GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glColor4f(0.4, 0.6,0.7,1);

   glBegin(GL_TRIANGLES);
      //Triángulo 1
      glVertex2f(75, 80);
      glVertex2f(10, 0);
      glVertex2f(75, -80);
   glEnd();
      
   glRotatef(45, 0, 0, 1);
   glBegin(GL_TRIANGLES);
      //Triángulo 2
      glVertex2f(-75, 80);
      glVertex2f(-10, 0);
      glVertex2f(-75, -80);
   glEnd();
   glutSwapBuffers();

}

void rectangulo(){

   glClearColor(0.9,0.8,0.6,1);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor4f(0.4, 0.6, 0.7, 1);

   glMatrixMode(GL_MODELVIEW);
   glTranslatef(20, 30, 0);
   glRotatef(45, 0, 0, 1);
   glRectf(-10, -10, 10, 10);

   glRectf(-20, -20, 20, 20);
   glutSwapBuffers();
}


void printMatriz(glm::mat4 matriz){
   for (int colum = 0; colum < 4; colum++) {
      for (int row = 0; row < 4; row++) {
        printf("%.2f\t", matriz[row][colum]); 
      }
      std::cout << std::endl;     
   }
   std::cout << std::endl;
}


int main(int argc, char **argv){

   glm::mat4 transform;
   transform=glm::mat4(1);
   std::cout << "Identidad: " << std::endl;
   printMatriz(transform);


   transform = glm::translate(transform, glm::vec3(5, 5, 0));
   std::cout << "Traslación: "<< std::endl;
   printMatriz(transform);

   transform = glm::rotate(transform, glm::radians(180.f), glm::vec3(1.0f, 0.0f, 0.0f));
   std::cout << "Rotación: "<< std::endl;
   printMatriz(transform);

   transform = glm::scale(transform, glm::vec3(5, 5, 0));
   std::cout << "Escala: "<< std::endl;
   printMatriz(transform);


   
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Movimientos");
   glutDisplayFunc(triangulos);
   glutReshapeFunc(reshape);
   glutMainLoop(); 
   return 0;
}

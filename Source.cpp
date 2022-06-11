#include <GL/freeglut.h>

void reshape(GLint w, GLint h){
   glViewport(0, 0, w, h); 
   glMatrixMode(GL_PROJECTION);
   glColor3f(1, 0, 0);

   glLoadIdentity();
   gluOrtho2D(-1.5, 1.5, -1.5, 1.5);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    
    glutSolidTeapot(1);
    glFlush();
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(20, 20);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Ejemplo de prueba");
    glClearColor(255, 255, 255, 0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

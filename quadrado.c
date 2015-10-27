#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int comando;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma linha");
  init();
  comando=118;
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  if(comando==118){
  	glColor3f (1.0, 0.0, 0.0);
  }else{
    glColor3f (0.0, 0.0, 1.0);
  }
  glBegin(GL_LINES);
  glVertex2i(30, 30);  glVertex2i(30,226);
  glVertex2i(226,226);  glVertex2i(226, 30);
  glVertex2i(30,30);  glVertex2i(226, 30);
  glVertex2i(30,226);  glVertex2i(226, 226);
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 118:
	comando=118;
	glutPostRedisplay();
	break;
  case 97:
  	comando=97;
	glutPostRedisplay();
  	break;
  }
}
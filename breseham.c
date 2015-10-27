#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void setPixel(int,int);
void display(void);
void keyboard(unsigned char key, int x, int y);

int comando=27;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma linha");
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

//desenhe uma reta verde do ponto (x, y)=(40, 200) ao ponto (x, y)=(200, 10).
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 1.0, 0.0);
  int i,x1=40, y1=200, x2=200, y2=10, Delta_x, Delta_y, new_e,x,y;
  Delta_x=x2-x1;
  Delta_y=y2-y1;
  x=x1;
  y=y1;
  new_e = 2*Delta_y - Delta_x;
 for(i=1; i <= Delta_x; i++){
   setPixel(x,y);
   while(new_e <= 0){
     y = y - 1;
     new_e = new_e + 2*Delta_x;
   }
   x = x + 1;
   new_e = new_e + 2*Delta_y;
 }
  glFlush();
}

void setPixel(int x,int y){
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}
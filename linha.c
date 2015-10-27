#include <GL/glut.h>
#include <stdlib.h>

void init(void);
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
  int i,x1=40, y1=200, x2=200, y2=10, dx, dy, new_e;
  dx=x2-x1;
  dy=y2-y1;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  new_e = 2*Delta_y - Delta_x;
 for(i=1, i <= Delta_x; i++){
   setPixel(x,y);
   while(new_e >= 0){
     y = y + 1;
     new_e = new_e - 2*Delta_x;
   }
   x = x + 1;
   new_e = new_e + 2*Delta_y
 }
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}
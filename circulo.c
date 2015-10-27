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
  int d,xc=128,yc=128,raio=50,x,y;
 x = 0;
 y = raio;
 d = 1 - raio;
	setPixel(xc,yc+raio);
	setPixel(xc,yc-raio);
	setPixel(xc-raio,yc);
	setPixel(xc+raio,yc);
 while(y > x){
   if(d < 0){
     d = d + 2*x + 3;
     x = x + 1;
   }
   else{
     d = d + 2*(x-y) + 5;
     x = x + 1;
     y = y - 1;
   }
	setPixel(xc + x, yc + y);
	setPixel(xc - x, yc + y);
	setPixel(xc + x, yc - y);
	setPixel(xc - x, yc - y);
	setPixel(xc + y, yc + x);
	setPixel(xc - y, yc + x);
	setPixel(xc + y, yc - x);
	setPixel(xc - y, yc - x);
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
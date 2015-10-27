#include <GL/glut.h>
#include <stdlib.h>

GLubyte tux[] = {
	0x0,  0x0,  0x0,  0x0, 
	0x0,  0x0,  0x0,  0x0, 
	0x10,  0x01,  0x0f,  0xf8, 
	0x10,  0x01,  0x0,  0x04,
	0x10,  0x01,  0x0,  0x02,
	0x10,  0x01,  0x0,  0x02,
	0x10,  0x01,  0x0,  0x02,
	0x10,  0x01,  0x0,  0x02,
	0x10,  0x01,  0x0,  0x04,
	0x10,  0x41,  0x03,  0xf8,
	0x10,  0xa1,  0x04,  0x0,
	0x11,  0x11,  0x08,  0x0,
	0x12,  0x09,  0x08,  0x0,
	0x14,  0x05,  0x04,  0x0,
	0x18,  0x03,  0x03,  0xfe,
	0x0,  0x0,  0x0,  0x0, 
	0x0,  0x0,  0x0,  0x0,
	0x0,  0x40,  0x0f,  0xfe,
	0x0,  0xa0,  0x08,  0x0, 
	0x0,  0xa0,  0x08,  0x0,
	0x0,  0xa0,  0x08,  0x0,
	0x01,  0x10,  0x08,  0x0,
	0x01,  0x10,  0x08,  0x0,
	0x02,  0x08,  0x1f,  0xf8,
	0x02,  0x08,  0x08,  0x0,
	0x04,  0x04,  0x08,  0x0,
	0x04,  0x04,  0x08,  0x0,
	0x08,  0x02,  0x08,  0x0,
	0x08,  0x02,  0x08,  0x0,
	0x10,  0x01,  0x0f,  0xfe,
	0x0,  0x0,  0x0,  0x0, 
	0x0,  0x0,  0x0,  0x0
};

GLfloat r,g,b;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Preenchendo regiões");
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
  r=0; g=1; b=0;
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);

  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);  glVertex2i(30,113);  
  glColor3f(0.0, 1.0, 0.0);  glVertex2i(113,113);
  glColor3f(0.0, 0.0, 1.0);  glVertex2i(113,30);  
  glColor3f(1.0, 1.0, 0.0);  glVertex2i(30,30); 
  glEnd();

  glEnable(GL_POLYGON_STIPPLE);
  glColor3f(1.0, 0.0, 1.0);
  glPolygonStipple(tux);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();
  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
	if (state == GLUT_DOWN) {
	  r=(GLfloat)rand()/(RAND_MAX+1.0);
	  g=(GLfloat)rand()/(RAND_MAX+1.0);
	  b=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	}
	break;
  }
}
#include <GL/glut.h>
#include <stdlib.h>

GLfloat rl[4],gl[4],bl[4],rf[4],gf[4],bf[4];
int comando;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void mudaCor(int index);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
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
	//inicializa as cores das bordas e fundos
  int i=0;
  comando=2;
  for(i=0;i<4;i++){
        rf[i]=1; gf[i]=1; bf[i]=0;
        rl[i]=0; gl[i]=0; bl[i]=0;
  }
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);
  
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[0], gf[0], bf[0]);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();
	
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[1], gf[1], bf[1]);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();
	
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[2], gf[2], bf[2]);
  glBegin(GL_POLYGON);
  glVertex2i(30,113);  
  glVertex2i(113,113);  
  glVertex2i(113,30);   
  glVertex2i(30,30);   
  glEnd();
	
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf[3], gf[3], bf[3]);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();

  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl[0], gl[0], bl[0]);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();
	
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl[1], gl[1], bl[1]);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();
	
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl[2], gl[2], bl[2]);
  glBegin(GL_POLYGON);
  glVertex2i(30,113);  
  glVertex2i(113,113);  
  glVertex2i(113,30);   
  glVertex2i(30,30);   
  glEnd();
	
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl[3], gl[3], bl[3]);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();
  
  glFlush();
  glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 98:
	comando=1;
	break;
  case 102:
	comando=2;
	break;
  }
}

void mudaCor(int index){
	if(comando==2){
		rf[index]=(GLfloat)rand()/(RAND_MAX+1.0);
		gf[index]=(GLfloat)rand()/(RAND_MAX+1.0);
		bf[index]=(GLfloat)rand()/(RAND_MAX+1.0);
	}else{
		rl[index]=(GLfloat)rand()/(RAND_MAX+1.0);
		gl[index]=(GLfloat)rand()/(RAND_MAX+1.0);
		bl[index]=(GLfloat)rand()/(RAND_MAX+1.0);
	}
}

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
	if (state == GLUT_DOWN) {
		if(x>=30&&x<=113 &&y>=143&y<=226){
			mudaCor(2);
		}else if(x>=143&&x<=226 &&y>=143&y<=226){
			mudaCor(3);
		}else if(x>=30&&x<=113 &&y>=30&y<=113){
			mudaCor(0);
		}else if(x>=143&&x<=226 &&y>=30&y<=113){
			mudaCor(1);
		}
    
  	}
	glutPostRedisplay();
	break;
  }
}
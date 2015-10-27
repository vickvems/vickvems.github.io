#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);

/* cores do quadrado */
GLfloat r=1.0, g=0.5, b=0.0, h=0;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  // inicia um temporizador. após 33ms ativa a funcao timer
  glutTimerFunc(33, timer, 1);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  //glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void timer(int value){
  h=h+1;
  if(h>359){
    h=0;
  }
  glutPostRedisplay();
  glutTimerFunc(33, timer, 1);
}

double getRadiano(GLfloat h){
  GLfloat val = PI / 180.0;
  return (double) h*val;
}

GLfloat calculaCor(GLfloat h, int cor, int vertice){
  GLfloat haux;
  GLfloat i=0.6, s=1, rAux, gAux, bAux;
  if(h>=360){
    haux=h-360;
  }else{
    haux=h;
  }
    
  if(haux>=0 && haux<120){
    haux=h;
    bAux=i*(1-s);
    rAux=i*(1+(s*cos(getRadiano(haux))/(cos(getRadiano(60.0-haux)))));
    gAux=3*i-(rAux+bAux);
  }else if(haux>=120 && haux<240){
    haux=h-120;
    rAux=i*(1-s);
    gAux=i*(1+(s*cos(getRadiano(haux))/(cos(getRadiano(60.0-haux)))));
    bAux=3*i-(rAux+gAux);
  }else if(haux>=240){
    haux=h-240;
    gAux=i*(1-s);
    bAux=i*(1+(s*cos(getRadiano(haux))/(cos(getRadiano(60.0-haux)))));
    rAux=3*i-(bAux+gAux);
  }
  //enviando a cor especificada
  if(cor==1){
    printf("\n Cor vermelha, R:%.2f Vertice:%d <---->",rAux, vertice);
    return rAux;
  }else if(cor==2){
     printf(" Cor Verde, G:%.2f Vertice:%d <---->",rAux, vertice);
     return gAux;
  }else{
     printf(" Cor Azul, B:%.2f Vertice:%d",rAux, vertice);
     return bAux;
  }
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (r, g, b);
  glBegin(GL_POLYGON);
  
  //os vertices giram pelo diagrama de cores de 0 a 360 graus, cada um possuindo um atraso de 90 graus
  printf("\n H vertices 1,2,3,4: %.2f, %.2f, %.2f, %.2f",h,h+90, h+180, h+270);
  //inf esq
  glColor3f (calculaCor(h+180, 1, 3), calculaCor(h+180, 2, 3), calculaCor(h+180, 3, 3));
  glVertex2f(0.25,0.25);
  //inf dir
  glColor3f (calculaCor(h+270, 1, 4), calculaCor(h+270, 2, 4), calculaCor(h+270, 3, 4));
  glVertex2f(0.75,0.25);
  //sup dir
  glColor3f (calculaCor(h, 1, 1), calculaCor(h, 2, 1), calculaCor(h, 3, 1));
  glVertex2f(0.75,0.75);
  //sup esq
  glColor3f (calculaCor(h+90, 1, 2), calculaCor(h+90, 2, 2), calculaCor(h+90, 3, 2));
  glVertex2f(0.25,0.75);
  glEnd();
  glFlush();
}
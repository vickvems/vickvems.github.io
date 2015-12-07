#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "png_texture.h"
#include <GL/freeglut.h>

#define SOL "sol.png"
#define MERCURIO "mercurio.png"
#define VENUS "venus.png"
#define MARTE "marte.png"
#define TERRA "terra.png"
#define LUA "lua.png"
#define JUPITER "jupiter.png"
#define SATURNO "saturno.png"
#define URANO "urano.png"
#define NETUNO "netuno.png"
#define PLUTO "plutao.png"
#define IO "io.png"
#define GANYMEDE "ganymede.png"
#define EUROPA "europa.png"
#define COSMIC "estrellas.png"
#define CALLISTO "callisto.png"

GLuint  text_sol;
GLuint  text_mercurio;
GLuint  text_venus;
GLuint  text_marte;
GLuint  text_terra;
GLuint  text_lua;
GLuint  text_jupiter;
GLuint  text_saturno;
GLuint  text_urano;
GLuint  text_netuno;
GLuint  text_pluto;
GLuint  text_io;
GLuint  text_ganymede;
GLuint  text_europa;
GLuint  text_cosmo;
GLuint  text_callisto;

int rodaX = 0;
int rodaY = 0;
int rodaZ = 0;
float zoom = -90;
int rotacionaX = 0;
int rotacionaY = 0;
float moveX =0;
float moveY =0;
int movimento = 1;
GLuint orbitas =0;
GLuint eixos=0;
GLuint planetas[15];

GLint WIDTH =800;
GLint HEIGHT=600;

//Função para carregar texturas
void carregar_texturas(void){
  text_sol = png_texture_load(SOL, NULL, NULL);
  text_mercurio = png_texture_load(MERCURIO, NULL, NULL);
  text_venus = png_texture_load(VENUS, NULL, NULL);
  text_marte = png_texture_load(MARTE, NULL, NULL);
  text_terra = png_texture_load(TERRA, NULL, NULL);
  text_lua = png_texture_load(LUA, NULL, NULL);
  text_jupiter = png_texture_load(JUPITER, NULL, NULL);
  text_saturno = png_texture_load(SATURNO, NULL, NULL);
  text_urano = png_texture_load(URANO, NULL, NULL);
  text_netuno = png_texture_load(NETUNO, NULL, NULL);
  text_pluto = png_texture_load(PLUTO, NULL, NULL);
  text_io = png_texture_load(IO, NULL, NULL);
  text_ganymede = png_texture_load(GANYMEDE, NULL, NULL);
  text_europa = png_texture_load(EUROPA, NULL, NULL);
  text_cosmo=png_texture_load(COSMIC, NULL, NULL);
  text_callisto =png_texture_load(CALLISTO, NULL, NULL);
}

// Funcao callback chamada quando o tamanho da janela  alterado
int w1=0;
int h1=0;
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	w1=w;
	h1=h;
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
		
		GLfloat b =(GLfloat) w/(GLfloat)h;

		// Especifica as dimenses da Viewport - melhor ficar no metodo desenha
    		 glViewport(0, 0, w,h);

        // Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa matriz de coordenadas de projeção
	glLoadIdentity();

                gluPerspective (16, b, 1, 800);
	printf("\n%f", b);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(0,80,200, 50,-20,30, 0,1,0);
	// Maior qualidade nos gráficos
   	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); 
}

void compilarObjetosDaCena()
{

	//Cria os 14 indices das listas para os 9 planetas e 5 luas
	int i;
	for( i = 1; i <15; i++)
		planetas[i] = glGenLists(i);
	
	orbitas = glGenLists(9);
	
	glNewList(planetas[1], GL_COMPILE);
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_mercurio);
		gluSphere(qobj,0.048,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[2], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_venus);
		gluSphere(qobj,0.121,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[3], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_terra);
		gluSphere(qobj,0.127,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	
	glNewList(planetas[4], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_marte);
		gluSphere(qobj,0.068,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[5], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_jupiter);
		gluSphere(qobj,0.750,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	
	glNewList(planetas[6], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_saturno);
		gluSphere(qobj,0.560,50,50);
		glDisable(GL_TEXTURE_2D); 
		glBegin(GL_LINE_LOOP);
		//aneis de saturno
		 for (i = 0; i <= 100 ; i++) {
		glVertex2f(0.7 * cos(2.0 * 3.14 * i / 100), 0.9 * sin(2.0 * 3.14 * i / 100) );
			glVertex2f(0.5 * cos(2.0 * 3.14 * i / 100),
					0.8 * sin(2.0 * 3.14 * i / 100) );
		glVertex2f(0.3 * cos(2.0 * 3.14 * i / 100),
					0.6 * sin(2.0 * 3.14 * i / 100) );
		
	}
		glEnd();
	glEndList();
	
	glNewList(planetas[7], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_urano);
		gluSphere(qobj,0.31,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[8], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_netuno);
		gluSphere(qobj,0.29,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[9], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_lua);
		gluSphere(qobj,0.03,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[10], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_pluto);
		gluSphere(qobj,0.2,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	glNewList(planetas[11], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_io);
		gluSphere(qobj,0.036,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
		glNewList(planetas[12], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_europa);
		gluSphere(qobj,0.031,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
		glNewList(planetas[13], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_ganymede);
		gluSphere(qobj,0.052,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
		glNewList(planetas[14], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_callisto);
		gluSphere(qobj,0.048,50,50);
		glDisable(GL_TEXTURE_2D); 
	glEndList();
	
	//----------- COMPILA ORBITAS --------//
	glNewList(orbitas, GL_COMPILE);
			//orbita mercurio
		glPushMatrix();
		//cincunferencia
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f( 3.28 * cos(2.0 * 3.14 * i / 100),
			(0.66+3.21 * sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//Orbirta venus
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(6.01 * cos(2.0 * 3.14 * i / 100),
			(0.04+6.01 * sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//orbita terra
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(7.48 * cos(2.0 * 3.14 * i / 100),
					( 0.12+7.47* sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//orbita marte
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(9.15  * cos(2.0 * 3.14 * i / 100),
					(0.85+9.11 * sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//orbita jupter
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(14.98 * cos(2.0 * 3.14 * i / 100),
					(0.73+14.9 * sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//orbita saturno
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(20.4 * cos(2.0 * 3.14 * i / 100),
					(1.01+20.38 * sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//orbita URANO
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(35.99 * cos(2.0 * 3.14 * i / 100),
					(1.59+35.95 * sin(2.0 * 3.14 * i / 100)) );
		}
		glEnd();
		glPopMatrix();
		
		//orbita netuno
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex2f(50.04 * cos(2.0 * 3.14 * i / 100),
					(0.5+50.03 * sin(2.0 * 3.14 * i / 100) ));
		}
		glEnd();
		glPopMatrix();
		
		//orbita plutÃo
		glPushMatrix();
		glBegin(GL_LINE_LOOP);
		 for (i = 0; i <= 100 ; i++) {
			glVertex3f(60.85 * cos(2.0 * 3.14 * i / 100),
					(14.69+59.06 * sin(2.0 * 3.14 * i / 100)), 20 * cos(2.0 * 3.14 * i / 100));
		}
		glEnd();
		glPopMatrix();
		
	glEndList();
}

GLuint texture = 0;
void background()
{
    int width = 600;
    int height =600;
    int length = 600;

    //start in this coordinates
    int x = 0;
    int y = 0;
    int z = 0;

    //center the square
    x = x - width / 2;
    y = y - height / 2;
    z = z - length / 2;

    glEnable(GL_TEXTURE_2D);

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

    glBindTexture(GL_TEXTURE_2D, text_cosmo);
    glBegin(GL_QUADS);      
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,  z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z); 
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
    glEnd();

    //FRONT
    glBindTexture(GL_TEXTURE_2D, text_cosmo);
    glBegin(GL_QUADS);  
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y,  z + length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length); 
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,  z + length);
    glEnd();

    //BOTTOM
    glBindTexture(GL_TEXTURE_2D, text_cosmo);
    glBegin(GL_QUADS);      
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y,  z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y,  z + length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y,  z + length); 
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,  z);
    glEnd();

    //TOP
    glBindTexture(GL_TEXTURE_2D, text_cosmo);
    glBegin(GL_QUADS);      
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length); 
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
    glEnd();

    //LEFT
    glBindTexture(GL_TEXTURE_2D, text_cosmo);
    glBegin(GL_QUADS);      
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z); 
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length); 
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y,  z + length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y,  z);     

    glEnd();

    //RIGHT
    glBindTexture(GL_TEXTURE_2D, text_cosmo);
    glBegin(GL_QUADS);  
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,  z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,  z + length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length); 
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
    glEnd();
//-----------------
    glDisable(GL_TEXTURE_2D);

}
//------------------------------------------
//Funcao callbak desenha.
void Desenha(void)
{

	/* usar buffer duplo, manda escrever no buffer de traz */
	glDrawBuffer(GL_BACK);
     
	// Limpa a janela de visualizao com a cor de fundo especificada
       	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslated(0, 0, zoom);
	glTranslated(moveX, 0, 0);
	glTranslated(0, moveY, 0);

	glRotated(-70, 1, 0, 0);

	glRotated(rodaX, 1, 0, 0);
	glRotated(rodaY, 0, 1, 0);
	glRotated(rodaZ, 0, 0, 1);
	
	//Desenha o Sol
	GLUquadric *qobj = gluNewQuadric();
	gluQuadricTexture(qobj,GL_TRUE);
	//-----------
	background();
	//------------
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,text_sol);
	glPushMatrix();
	glRotated(-1.48*a, 0, 0, 1);
	gluSphere(qobj,1.39,25,25);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D); 
	
	glCallList(orbitas); 

	//mercurio
	glPushMatrix();
		
		//translação do planeta
		if(movimento ==1)
			glTranslatef((3.28 * cos(2.0 * 3.14 * a*0.48 / 100)),(0.66+ 3.21* sin(2.0 * 3.14 * a*0.48 / 100)), 0);
		//rotação do planeta
		glRotated(-0.45*a, 0, 0, 1);
		glCallList(planetas[1]); 
	glPopMatrix();

	//venus
	glPushMatrix();
		//translação
		if(movimento ==1)
			glTranslatef((6.01 * cos(2.0 * 3.14 * a*3.5 / 100)),(0.04+6.01* sin(2.0 * 3.14 * a*3.5 / 100)), 0);
		//rotacao
		glRotated(0.16*a, 0, 0, 1);
		glCallList(planetas[2]);
	glPopMatrix();
	
	//terra
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((7.48* cos(2.0 * 3.14 * a*2.9 / 100)),(0.12+7.47 * sin(2.0 * 3.14 * a*2.9 / 100)), 0);
		//rotacao
		glRotated(-40*a, 0, 0, 1);
		glCallList(planetas[3]);
	glPopMatrix();
	
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((7.48* cos(2.0 * 3.14 * a*2.9 / 100)),(0.12+7.47 * sin(2.0 * 3.14 * a*2.9 / 100)), 0);
		//translacao da lua
		glTranslatef(0.37*cos(2.0 * 3.14 * a*30/ 100),0.02+0.37*sin(2.0 * 3.14 * a*30/ 100), 0);
		glRotated(-1.46*a, 0, 0, 1);
		glCallList(planetas[9]);
	glPopMatrix();
	
	//marte
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((9.15 * cos(2.0 * 3.14 * a*2.4 / 100)),(0.85+9.11* sin(2.0 * 3.14 * a*2.4 / 100)), 0);
		//rotacao
		glRotated(-32*a, 0, 0, 1);
		glCallList(planetas[4]);
	glPopMatrix();
	
	//jupter
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((14.98 * cos(2.0 * 3.14 * a*1.3 / 100)),(0.73+14.9 * sin(2.0 * 3.14 * a*1.3 / 100)), 0);
		//rotacao
		glRotated(-96*a, 0, 0, 1);
		glCallList(planetas[5]);
		
		//Io
		glTranslatef(0.92*cos(2.0 * 3.14 * a*13/ 100),(0.001+0.92*sin(2.0 * 3.14 * a*13/ 100)), 0.2*cos(2.0 * 3.14 * a*5/ 100));
		glCallList(planetas[11]);
	glPopMatrix();
	
	//Europa
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((14.98 * cos(2.0 * 3.14 * a*1.3 / 100)),(0.73+14.9 * sin(2.0 * 3.14 * a*1.3 / 100)), 0);
			glTranslatef(1.17*cos(2.0 * 3.14 * a*12/ 100),(0.006+1.17*sin(2.0 * 3.14 * a*12/ 100)), 
			0);
		glCallList(planetas[12]);
	glPopMatrix();
	
	//Ganymede
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((14.98 * cos(2.0 * 3.14 * a*1.3 / 100)),(0.73+14.9 * sin(2.0 * 3.14 * a*1.3 / 100)), 0);
		glTranslatef(1.57*cos(2.0 * 3.14 * a*5/ 100),(0.001+1.57*sin(2.0 * 3.14 * a*5/ 100)), 
			0.7*cos(2.0 * 3.14 * a*5/ 100));
		glCallList(planetas[13]);
	glPopMatrix();
	
	//Callisto
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((14.98 * cos(2.0 * 3.14 * a*1.3 / 100)),(0.73+14.9 * sin(2.0 * 3.14 * a*1.3 / 100)), 0);
		glTranslatef(2*cos(2.0 * 3.14 * a*2/ 100),(0.014+2*sin(2.0 * 3.14 * a*2/ 100)), 
			cos(2.0 * 3.14 * a*2/ 100));
		glCallList(planetas[14]);
	glPopMatrix();
	
	//saturno
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((20.4* cos(2.0 * 3.14 * a*0.9 / 100)),(1.01+20.38* sin(2.0 * 3.14 * a*0.9 / 100)), 0);
		//inclinacao do planeta e aneis
		glRotated(27, 1, 0, 0);
		//rotacao
		glRotated(-92*a, 0, 0, 1);
		glCallList(planetas[6]);
		
		//Lua de saturno
		glTranslatef(1.22*(cos(2.0 * 3.14 * a*10 / 100)),(0.03+1.22*sin(2.0 * 3.14 * a*10 / 100)), 0);
		glutSolidSphere(0.05, 25,25);
	glPopMatrix();
	
	//urano
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((35.99 * cos(2.0 * 3.14 * a*0.6 / 100)),(1.59+35.95 * sin(2.0 * 3.14 * a*0.6 / 100)), 0);
		//rotacao
		glRotated(77.4*a, 0, 0, 1);
		glCallList(planetas[7]);
	glPopMatrix();
	
	//netuno
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((50.04* cos(2.0 * 3.14 * a*0.5 / 100)),(0.5+50.03 * sin(2.0 * 3.14 * a*0.5 / 100)), 0);
		//rotacao
		glRotated(-60*a, 0, 0, 1);
		glCallList(planetas[8]);
	glPopMatrix();
	
		//plutao
	glPushMatrix();
		//translacao
		if(movimento ==1)
			glTranslatef((60.85 * cos(2.0 * 3.14 * a*0.4 / 100)),(14.69+59.06 * sin(2.0 * 3.14 * a*0.4 / 100)), 
		20 * cos(2.0 * 3.14 * a*0.4 / 100));
		//rotacao
		glRotated(-6.25*a, 0, 0, 1);
		glCallList(planetas[10]);
	glPopMatrix();
	
	glutSwapBuffers();
}

// Inicializa parmetros de rendering
void Inicializa (void)
{
	//Obs: o uso de textura consiste apenas em dois passos: Carga e Aplicação.
	
	// Habilitar o uso de texturas
	glEnable ( GL_TEXTURE_2D );
	glEnable(GL_COLOR_MATERIAL);
	//carregar texturas
	carregar_texturas();
	//negocio para nao ficar mais transparente
	glEnable(GL_DEPTH_TEST);
	
	// Define a cor de fundo da janela de visualizao como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//chama metodo para compilar os objetos e gerar a listas de exibicao
	compilarObjetosDaCena();
}

//funcao chamada sempre que o opengl está desocupado
//fica sempre atualizadno a tela
static void 
idle(void)
{
    glutPostRedisplay();
}

void keyboard2(int key, int x, int y)
{
   switch (key) {
	case GLUT_KEY_PAGE_UP:
		glutFullScreen ( );
	break;
 case GLUT_KEY_UP:
   	moveY -= 0.5f;
   break;

 case GLUT_KEY_DOWN:
   	moveY += 0.5f;
   break;

 case GLUT_KEY_LEFT:
   	moveX += 0.5f;
   break;

 case GLUT_KEY_RIGHT:
   	moveX -= 0.5f; 
   break;
   }
	glutPostRedisplay(); //redesenha tela
}

void HandleMouse ( int button, int state, int x, int y )
{

	if(button == 3) //rolagem para cima(nao funcionou no windows)
		zoom+=2;
	else if(button == 4) //rolagem para baixo
		zoom-=2;
	
     glutPostRedisplay(); //redesenha tela
}

//funcao que trata eventos do teclado
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   	break;
     case '3':
	glEnable(GL_DEPTH_TEST); //abilitar remover transparencia
	break;
      case '4':
	glDisable(GL_DEPTH_TEST);
	break;
	case 'p':
		if(movimento == 1)
			movimento = 0;
		else movimento = 1;
		break;
      case 'x':
         rodaX +=2;
	 glutPostRedisplay();
         break;
      case 'X':
         rodaX -=2;
	 glutPostRedisplay();
         break;
      case 'y':
         rodaY+=2;
	 glutPostRedisplay();
         break;
      case 'Y':
         rodaY-=2;
	 glutPostRedisplay();
         break;
      case 'z':
         rodaZ+=2;
	 glutPostRedisplay();
         break;
      case 'Z':
         rodaZ-=2;
	 glutPostRedisplay();
         break;
	case '1':
         zoom+=0.3;
	 glutPostRedisplay();
         break;
	case '2':
         zoom-=0.3;
	 glutPostRedisplay();
         break;
      case 27:
         exit(0);
	 break;
   }
}

//Funcao que trata eventos do mouse enquanto o botao permanece pressionado
int Y=0, X=0;
void MoveMouseBotaoPressionado(int x, int y)
{
	if(y > Y)
		moveY -= 0.03;
	else moveY += 0.03;

	if(x > X)
		moveX += 0.03;
	else moveX -= 0.03;

	Y = y;
	X = x;
      glutPostRedisplay();
}


int main(int argc, char **argv) {

     glutInit(&argc,argv);

     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); //GLUT_DEPTH: buffer para evitar transparencia(por profundidade)
     glutInitWindowSize(1200,720); //tamanha inicial da janela
     glutInitWindowPosition(10,10); //posicao inicial
     glutCreateWindow("Sistema solar - Angele/Victor"); //nome da janela
     glutDisplayFunc(Desenha); //funcao onde fica todas as rotinas de desenho
     glutMouseFunc(HandleMouse); //cliques do mouse
     glutMotionFunc(MoveMouseBotaoPressionado); 
     glutReshapeFunc(AlteraTamanhoJanela); //configura o tamanho da janela, camera e etc
     Inicializa(); //inicializa alguns parametros
     glutKeyboardFunc(keyboard); //teclas
     glutSpecialFunc(keyboard2); //teclas especiais
     glutIdleFunc(idle); 
     glutMainLoop(); //inicia maquina de estados
}

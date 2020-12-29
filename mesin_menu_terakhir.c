#include "header.h"
void createMenuLast(){
	glLineWidth(2);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-1.0,-0.8,0);
		glVertex3f(1.0,-0.8,0);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-1.0,0.8,0);
		glVertex3f(1.0,0.8,0);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-0.8,-0.8,0);
		glVertex3f(-0.8,0.8,0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(0.8,-0.8,0);
		glVertex3f(0.8,0.8,0);
	glEnd();
	glColor3f(1,1,0);
	RenderString(-0.5f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24, "WELLCOME TO GAME TENBIR BETA v0.1");
	glColor3f(1,1,1);
	if (win == 1)
	{
		RenderString(-0.0f, 0.4f, GLUT_BITMAP_TIMES_ROMAN_24, "MENANG");
	}else{
		RenderString(-0.0f, 0.4f, GLUT_BITMAP_TIMES_ROMAN_24, "KALAH");
	}
	RenderString(-0.5f, 0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "O untuk bermain 1 player");
	RenderString(-0.5f, -0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "P untuk bermain 2 player");
	RenderString(-0.5f, -0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "X untuk menghentikan permainan");

	if (start == 0)
		{
		glutTimerFunc(0, createMenuLast, 0);
		}	
	glutKeyboardFunc(menuFun);
	glFlush();
	
}
#ifndef __gamewindow_h__
#define __gamewindow_h__

#define SQUARE_SIZE	100

typedef struct gameWindow {
	int running;	
	GLfloat height;
	GLfloat width;
} GameWindow;

void gameWindowInit(GameWindow g) 
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glViewport(0.0f,0.0f, g.width, g.height);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, g.width, 0, g.height);
}

void gameWindowRender() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2f(0.0f,0.0f);
		glVertex2f(SQUARE_SIZE,0.0f);
		glVertex2f(SQUARE_SIZE,SQUARE_SIZE);
		glVertex2f(0.0f,SQUARE_SIZE);
	glEnd();
	
	glfwSwapBuffers();
}

void gameWindowUpdate() 
{
	
}

#endif

#ifndef __gamewindow_h__
#define __gamewindow_h__

typedef struct gameWindow {
	int running;	
	GLfloat height;
	GLfloat width;
} GameWindow;

void gameWindowInit(GameWindow g) 
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void gameWindowRender() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.5f, -0.5f);
		glVertex2f(	0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();
	
	glfwSwapBuffers();
}

void gameWindowUpdate() 
{
	
}

#endif

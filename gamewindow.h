#ifndef __gamewindow_h__
#define __gamewindow_h__

typedef struct gameWindow {
	int running;	
} GameWindow;

void gameWindowRender() {
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers();
}

void gameWindowUpdate() {
	
}

#endif

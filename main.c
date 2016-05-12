#include <GL/glfw.h>
#include "gamewindow.h"

GameWindow gameWindow;

int main(int argc, char **argv)
{
	glfwInit();
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
	glfwOpenWindow(600,600,8,8,8,8,0,0,GLFW_WINDOW);
	glfwSetWindowTitle("OpenGL Game");
	
	gameWindow.running = 1; 
	while(gameWindow.running) {
		gameWindowRender();
		gameWindowUpdate();
		gameWindow.running = glfwGetWindowParam(GLFW_OPENED);
	}
	glfwTerminate();
	return 0;
}

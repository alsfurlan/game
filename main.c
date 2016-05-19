#include "bibliotecas.h"
#include "gamewindow.h"

int main(int argc, char **argv)
{
	gameWindow.running = 1; 
	gameWindow.height = 600;
	gameWindow.width  = 600;
	
	// Inicialização GLFW
	glfwInit();
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
	glfwOpenWindow(gameWindow.width,gameWindow.height,8,8,8,8,0,0,GLFW_WINDOW);
	glfwSetWindowTitle("OpenGL Game");
	
	glewInit();	
	// Inicialização das configurações do game
	gameWindowInit();
	while(gameWindow.running) {
		gameWindowRender();
		gameWindowUpdate();
		gameWindow.running = glfwGetWindowParam(GLFW_OPENED);
	}
	
	glfwTerminate();
	return 0;
}

#include <GL/glfw.h>

int main(int argc, char **argv)
{
	glfwInit();
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
	glfwOpenWindow(600,600,8,8,8,8,0,0,GLFW_WINDOW);
	glfwSetWindowTitle("OpenGL Game");
	int running = 1;
	while(running) {
		glClear(GL_COLOR_BUFFER_BIT);
		running = glfwGetWindowParam(GLFW_OPENED);
		glfwSwapBuffers();
	}
	glfwTerminate();
	return 0;
}

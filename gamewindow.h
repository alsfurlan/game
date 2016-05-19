#ifndef __gamewindow_h__
#define __gamewindow_h__

#include <GL/glfw.h>
#define SQUARE_SIZE	100

typedef struct gameWindow {
	int running;	
	GLfloat height;
	GLfloat width;
	GLuint vertexBufferID;
	GLuint textureBufferID;
} GameWindow;

typedef struct {
	GLfloat positionCoordinates[3];
	GLfloat textureCoordinates[2];
} VertexData;

VertexData vertexData[4] = {
	{{0.0f,0.0f,0.0f}, {0.0f, 0.0f}},
	{{SQUARE_SIZE,0.0f,0.0f}, {1.0f, 0.0f}},
	{{SQUARE_SIZE,SQUARE_SIZE,0.0f}, {1.0f, 1.0f}},
	{{0.0f,SQUARE_SIZE,0.0f}, {0.0f, 1.0f}}
};

GLuint gameWindowLoadAndBufferImage(const char *filename)
{
	GLFWimage imageData;
	GLuint textureBufferID;
	
	glfwReadImage(filename, &imageData, NULL);
	
	glGenTextures(1, &textureBufferID);
	glBindTexture(GL_TEXTURE_2D, textureBufferID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageData.Width, imageData.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData.Data);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glfwFreeImage(&imageData);
	
	return textureBufferID;
}

void gameWindowInit(GameWindow g) 
{
	g.vertexBufferID = 0;
 	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glViewport(0.0f,0.0f, g.width, g.height);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, g.width, 0, g.height);
	
	glGenBuffers(1, &g.vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER,g.vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,sizeof(VertexData),(GLvoid *)offsetof(VertexData,positionCoordinates));
	 
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *) offsetof(VertexData, textureCoordinates));
	
	g.textureBufferID = gameWindowLoadAndBufferImage("imagens/rocket.tga");
	
	
}

void gameWindowRender() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_QUADS, 0, 4);
	glfwSwapBuffers();
}

void gameWindowUpdate() 
{
	 
}


#endif

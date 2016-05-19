#ifndef __sprite_h__
#define __sprite_h__
#include<stdio.h>
typedef struct {
	GLfloat x;
	GLfloat y;	
} Position;

typedef struct {
	GLuint textureBufferID;
	Position position;
} Sprite;

void spriteRender(Sprite s)
{
	glBindTexture(GL_TEXTURE_2D, s.textureBufferID);
	glDrawArrays(GL_QUADS,0,4);
}

void spriteUpdate()
{
	
}

#endif

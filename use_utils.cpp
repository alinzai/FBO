#include "esUtil.h"
#include "use_utils.hpp"
#include <stdio.h>

unsigned    createTexture(int width,int height)
{
    unsigned    textureId;
    glGenTextures(1,&textureId);
    glBindTexture(GL_TEXTURE_2D,textureId);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glTexImage2D(
        GL_TEXTURE_2D
        ,0
        ,GL_RGB
        ,width
        ,height
        ,0
        ,GL_RGB
        ,GL_UNSIGNED_BYTE
        ,0);
    return  textureId;
}


std::pair<unsigned, unsigned> createFBO(int width, int height, unsigned textureId)
{
	std::pair<unsigned, unsigned> buf;
	glGenFramebuffers(1, &buf.first);
	glBindFramebuffer(GL_FRAMEBUFFER, buf.first);
	glGenRenderbuffers(1, &buf.second);
	glBindRenderbuffer(GL_RENDERBUFFER, buf.second);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, buf.first);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, buf.second);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureId, 0);
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		fprintf(stderr, "GLEW Error: %s\n", "FRAME BUFFER STATUS Error!");
		return buf;
	}
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return buf;

}
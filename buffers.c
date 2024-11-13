#include "HGL/buffers.h"

GLframebuffer* FB_Create()
{
	return (GLframebuffer*) malloc(sizeof(GLframebuffer));
}

GLframebuffer* FB_Existing(intptr_t address, int width, int height)
{
	GLframebuffer * fb = FB_Create();
	{
		fb->width  = width;
		fb->height = height;
		fb->len    = width * height;
		fb->pixels = (uint32_t *) address;
	}
	return fb;
}

void FB_Fill(GLframebuffer * fb, uint32_t value)
{
	buffers_fillU32(fb->pixels, 0, fb->len, value);
}

void buffers_fillU32(uint32_t * bff, int offset, int len, uint32_t value)
{
	for (int i = offset; i < len; i++)
		bff[i] = value;
}
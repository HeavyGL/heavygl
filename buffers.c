#include "HGL/buffers.h"

GLframebuffer* fb_create()
{
	return (GLframebuffer*) malloc(sizeof(GLframebuffer));
}

GLframebuffer* fb_existing(intptr_t address, int width, int height)
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

void fb_fill(GLframebuffer * fb, uint32_t value)
{
	buffers_fillU32(fb->pixels, 0, fb->len, value);
}

void fb_copy(GLframebuffer * dstfb, GLframebuffer * srcfb)
{
	int dstlen = dstfb->len;
	int srclen = srcfb->len;

	// Minimum length for both buffers (SECURITY REASONS)
	int len = dstlen > srclen ? srclen : dstlen;

	buffers_copyU32(dstfb->pixels, srcfb->pixels, 0, len);
}

void buffers_fillU32(uint32_t * bff, int offset, int len, uint32_t value)
{
	for (int i = offset; i < len; i++)
		bff[i] = value;
}

void buffers_copyU32(uint32_t * dst, uint32_t * src, int offset, int len)
{
	for (int i = offset; i < len; i++)
		dst[i] = src[i];
}
/*
 * HGL Specification 1.2
 */
#pragma once

#ifndef BUFFERS_H
#define BUFFERS_H 1

#include <stdint.h>
#include <stdlib.h>

typedef struct {
	int width, height, len;
	uint32_t* pixels; // Based on the 32-bit RGB color scheme
} GLframebuffer;

GLframebuffer* FB_Create();
GLframebuffer* FB_Existing(intptr_t, int, int);
void FB_Fill(GLframebuffer*, uint32_t);

void buffers_fillU32(uint32_t*, int, int, uint32_t);

#endif // BUFFERS_H

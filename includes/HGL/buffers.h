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

/**
 * =================================================================
 * EN: Creates an empty GLframebuffer.
 * ES: Crea un nuevo GLframebuffer.
 * =================================================================
 * NOTE: This method IS NOT the same as "FB_Existing(intptr_t, int, int)".
 */
GLframebuffer* FB_Create();

/**
 * =================================================================
 * EN: Creates a new GLframebuffer using the selected address.
 * ES: Crea un nuevo GLframebuffer usando la direccion seleccionada.
 * =================================================================
 * NOTE: Empty.
 */
GLframebuffer* FB_Existing(intptr_t, int, int);

/**
 * =================================================================
 * EN: Fills a GLframebuffer using a color.
 * ES: Rellena un GLframebuffer con un color.
 * =================================================================
 * NOTE: This method IS NOT the same as "glClear(void)".
 */
void FB_Fill(GLframebuffer*, uint32_t);

/**
 * =================================================================
 * EN: Fills a normal buffer using the specified value.
 * ES: Rellena un buffer cualquiera usando el valor especificado.
 * =================================================================
 * NOTE: This method IS NOT the same as "glClear(void)".
 */
void buffers_fillU32(uint32_t*, int, int, uint32_t);

#endif // BUFFERS_H

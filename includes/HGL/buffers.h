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
 * NOTE: This method IS NOT the same as "fb_existing(intptr_t, int, int)".
 */
GLframebuffer* fb_create();

/**
 * =================================================================
 * EN: Creates a new GLframebuffer using the selected address.
 * ES: Crea un nuevo GLframebuffer usando la direccion seleccionada.
 * =================================================================
 * NOTE: Empty.
 */
GLframebuffer* fb_existing(intptr_t, int, int);

/**
 * =================================================================
 * EN: Fills a GLframebuffer using a color.
 * ES: Rellena un GLframebuffer con un color.
 * =================================================================
 * NOTE: Empty.
 */
void fb_fill(GLframebuffer*, uint32_t);

/**
 * =================================================================
 * EN: Copies the second framebuffer to the first one.
 * ES: Copia el contenido del segundo framebuffer al primero.
 * =================================================================
 * NOTE: Empty.
 */
void fb_copy(GLframebuffer*, GLframebuffer*);

/**
 * =================================================================
 * EN: Fills a normal buffer using the specified value.
 * ES: Rellena un buffer cualquiera usando el valor especificado.
 * =================================================================
 * NOTE: Empty.
 */
void buffers_fillU32(uint32_t*, int, int, uint32_t);

/**
 * =================================================================
 * EN: Copies the second buffer to the first one.
 * ES: Copia el contenido del segundo buffer al primero.
 * =================================================================
 * NOTE: Empty.
 */
void buffers_copyU32(uint32_t*, uint32_t*, int, int);

#endif // BUFFERS_H

/*
 * HGL Specification 1.2
 */
#pragma once

#ifndef HGL_H
#define HGL_H 1

/* Enable */
#define GL_DOUBLEBUFFER 0xc32

/* String */
#define GL_VERSION  0x1F02

/* Error */
#define GL_NO_ERROR                       0x0
#define GL_INVALID_ENUM                   0x500
#define GL_INVALID_VALUE                  0x501
#define GL_INVALID_OPERATION              0x502
#define GL_STACK_OVERFLOW                 0x503
#define GL_STACK_UNDERFLOW                0x504
#define GL_OUT_OF_MEMORY                  0x505
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x506
#define GL_CONTEXT_LOST                   0x507
#define GL_TABLE_TOO_LARGE1               0x8031

#include <stdint.h>

typedef int GLerror;

/*** HeavyGL Common Functions ***/

// --- [ glClear ] ---

/**
 * =================================================================
 * EN: Clears the main color buffer.
 * ES: Limpia el buffer de color actual.
 * =================================================================
 * NOTE: Empty.
 */
void glClear();

// --- [ glClearColor ] ---

/**
 * =================================================================
 * EN: Specifies the color to clear the color buffer.
 * ES: Especifica el color a limpiar el buffer de color.
 * =================================================================
 * NOTE: This method IS NOT the same as "glClear(void)".
 */
void glClearColor(float, float, float);

/**/ */
void glDisable();

void glEnable();

// --- [ glFillRect ] ---

/**
 * =================================================================
 * EN: Fills a rect based on the x, y, width and height position
 * ES: Rellena un rectangulo basado en las coordenadas x, y, width
 *     y height.
 * =================================================================
 * NOTE: Empty.
 */
void glFillRect(float, float, float, float);

// --- [ glFlush ] ---

/**
 * =================================================================
 * EN: Sends the data from the back framebuffer to the front
 *     framebuffer.
 * ES: Envía información desde el "framebuffer" trasero hasta el
 *     delantero.
 * =================================================================
 * NOTE: Empty.
 */
void glFlush();

// --- [ glGetError ] ---

GLerror glGetError();

// --- [ glGetString ] ---

/**
 * =================================================================
 * EN: Returns a string based on the provided ID.
 * ES: Devuelve una cadena de texto basada en el identificador
 *     proveído.
 * =================================================================
 * NOTE: Empty.
 */
const char* glGetString(int);

/*** HeavyGL Special Functions ***/

// --- [ glXSetContext ] ---

/**
 * =================================================================
 * EN: Specifies the rendering context.
 * ES: Especifica el contexto de renderizado.
 * =================================================================
 * NOTE: Empty.
 */
void glXSetContext(intptr_t, int, int);

#endif // HGL_H

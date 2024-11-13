/*
 * HGL Specification 1.2
 */
#pragma once

#ifndef HGL_H
#define HGL_H 1

#define GL_VERSION  0x1F02

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

/*** HeavyGL Special Functions ***/

/**
 * =================================================================
 * EN: Specifies the color to clear the color buffer.
 * ES: Especifica el color a limpiar el buffer de color.
 * =================================================================
 * NOTE: This method IS NOT the same as "glClear(void)".
 */
void glXSetContext(intptr_t, int, int);

/*** HeavyGL Common Functions ***/

// --- [ glClear ] ---

/**
 * =================================================================
 * EN: Clears the main color buffer.
 * ES: Limpia el buffer de color actual.
 * =================================================================
 * NOTE: Not specified yet.
 */
void glClear();

// --- [ glClearColor ] ---

/**
 * =================================================================
 * EN: Returns any error ocurred during the HeavyGL runtime.
 * ES: Devuelve cualquier error ocurrido en el tiempo de ejecución
 *     de HeavyGL.
 * =================================================================
 * NOTE: The state of the variable `gl_error' gets deleted
 *       after retrieving its state.
 * =================================================================
 */
void glClearColor(float, float, float);

// --- [ glGetError ] ---

GLerror glGetError();

// --- [ glGetString ] ---

/**
 * =================================================================
 * EN: Returns a string based on the provided ID.
 * ES: Devuelve una cadena de texto basada en el identificador
 *     proveído.
 * =================================================================
 * NOTE: Not specified yet.
 */
const char* glGetString(int);

#endif // HGL_H

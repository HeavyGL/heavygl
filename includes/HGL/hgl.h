/*
 * HeavyGL Specification 1.1
 */

#pragma once

#ifndef HGL_H
#define HGL_H 1

#define GL_VENDOR   0x1F00
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

/* HeavyGL Special Functions */
void glXSetContext(intptr_t, int, int);

/* HeavyGL Common Functions */

// --- [ glClearColor ] ---

void glClearColor(float, float, float);

// --- [ glClear ] ---

void glClear();

// --- [ glFillRect ] ---

void glFillRect(float, float, float, float);

GLerror glGetError();

// --- [ glGetString ] ---

const char* glGetString(int);

#endif

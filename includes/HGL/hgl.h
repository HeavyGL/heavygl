/*
 * HeavyGL Specification 1.1
 */

#pragma once

#ifndef HGL_H
#define HGL_H 1
#include <stdint.h>

typedef int GLerror;

/* HeavyGL Special Functions */
void glXSetContext(intptr_t, int, int);

/* HeavyGL Common Functions */
void glClearColor(float, float, float);
void glClear();

void glFillRect(float, float, float, float);

GLerror glGetError();

#endif

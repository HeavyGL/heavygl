#pragma once

#ifndef HGL_H
#define HGL_H 1

typedef int GLerror;

/* HeavyGL Special Functions */
void glXSetContext(intptr_t, int, int);

/* HeavyGL Common Functions */
void glClearColor(float, float, float);
void glClear();

GLerror glGetError();

#endif

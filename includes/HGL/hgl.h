#pragma once

#ifndef HGL_H
#define HGL_H 1

typedef struct GLerror_ {

    const char* msg;
    int type;

} GLerror;

/* HeavyGL Special Functions */
void glXSetPxBuffer(intptr_t, int, int);

/* HeavyGL Common Functions */
void glClearColor(float, float, float);
void glClear();

GLerror glGetError();

#endif

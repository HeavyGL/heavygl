/*
 * HeavyGL Specification 1.1
 */

#ifdef __WIN32__

#include "HGL/hgl.h"
#include <stdint.h>

static int width = 0, height = 0, area = 0;
static uint32_t * pixels = NULL;
static int error = 0;

static int clearColor = 0;

/* HeavyGL Special Functions */
void glXSetContext(intptr_t address, int w, int h)
{
    width = w;
    height = h;
    area = w * h;
    pixels = (uint32_t *) address;
}

/* HeavyGL Common Functions */
void glClearColor(float r, float g, float b)
{
    int ubr = (int) ((float) r * 255.0);
    int ubg = (int) ((float) g * 255.0);
    int ubb = (int) ((float) b * 255.0);

    clearColor = (ubr << 16) + (ubg << 8) + (ubb);
}

void glClear()
{
    for (int i = 0; i < area; i++)
        pixels[i] = clearColor;
}

GLerror glGetError()
{
    return error;
}

#endif

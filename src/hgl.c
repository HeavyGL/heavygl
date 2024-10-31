#include "HGL/hgl.h"
#include <stdint.h>

static int width = 0, height = 0, area = 0;
static uint32_t * pixels = NULL;
static GLerror error = NULL;

static int clearColor = 0;

/* HeavyGL Special Functions */
void glXSetPxBuffer(intptr_t address, int w, int h)
{
    width = w;
    height = h;

    pixels = (uint32 *) address;
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

void glThrowError(int type, const char* msg)
{
    GLerror error_;
    error_.msg = msg;
    error_.type = msg;

    error = error_;
}

GLerror glGetError()
{
    return error;
}

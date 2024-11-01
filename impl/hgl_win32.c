/*
 * HeavyGL Specification 1.1
 */

#ifdef __WIN32__

#include "HGL/hgl.h"
#include <stdint.h>

static int width = 0, height = 0, area = 0;
static uint32_t * pixels = NULL;
static int gl_error = GL_NO_ERROR;

static int gl_clear_color = 0;

/* HeavyGL Special Functions */
void glXSetContext(intptr_t address, int w, int h)
{
    width = w;
    height = h;
    area = w * h;
    pixels = (uint32_t *) address;
}

/* HeavyGL Common Functions */

// --- [ glClearColor ] ---

void glClearColor(float r, float g, float b)
{
    if ((r < 0 || r > 1) || (g < 0 || g > 1) || (b < 0 || b > 1))
    {
        gl_error = GL_INVALID_VALUE;
        return;
    }

    int ubr = (int) ((float) r * 255.0);
    int ubg = (int) ((float) g * 255.0);
    int ubb = (int) ((float) b * 255.0);

    gl_clear_color = (ubr << 16) + (ubg << 8) + ubb;
}

void glClear()
{
    for (int i = 0; i < area; i++)
        pixels[i] = gl_clear_color;
}

GLerror glGetError()
{
    GLerror err = gl_error;
    gl_error = GL_NO_ERROR;
    return err;
}

const char* glGetString(int id)
{
    switch (id)
    {
        case GL_VERSION:
            return "Version 1.1";

        case GL_VENDOR:
            return "Community Edition";

        default:
            return "null";
    }
}

#endif

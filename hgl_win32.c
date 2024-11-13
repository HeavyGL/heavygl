#ifdef __WIN32__

#include "HGL/hgl.h"
#include "HGL/buffers.h"
#include "HGL/colors.h"

#include <stdint.h>

/* Static variables */
static GLframebuffer * fb = NULL;
static GLerror gl_error = GL_NO_ERROR;

static int gl_clear_color = 0;

/*** HeavyGL Special Functions ***/

void glXSetContext(intptr_t address, int w, int h)
{
    if (fb == NULL)
		fb = FB_Existing(address, w, h);
}

/*** HeavyGL Common Functions ***/

// --- [ glClearColor ] ---

void glClearColor(float r, float g, float b)
{
    if ((r < 0 || r > 1) || (g < 0 || g > 1) || (b < 0 || b > 1))
    {
        gl_error = GL_INVALID_VALUE;
        return;
    }

    gl_clear_color = ColorRGB_3F(r, g, b);
}

// --- [ glClear ] ---

void glClear()
{
	FB_Fill(fb, gl_clear_color);
}

// --- [ glGetError ] ---

GLerror glGetError()
{
    GLerror tmp = gl_error;
    gl_error = GL_NO_ERROR;
    return tmp;
}

// --- [ glGetString ] ---

const char* glGetString(int id)
{
    switch (id)
    {
		/** RETURNS THE HEAVYGL VERSION */
        case GL_VERSION:
            return "a1.2.0 (preview)";
			
		/** WORKAROUND FOR INVALID ID'S */
        default:
            return "null";
    }
}

#endif

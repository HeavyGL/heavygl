#ifdef __WIN32__

#include "HGL/hgl.h"
#include "HGL/buffers.h"
#include "HGL/colors.h"

#include <stdint.h>

/* Static variables */
static GLframebuffer * frontfb = NULL;
static GLframebuffer * backfb  = NULL;
static GLerror gl_error = GL_NO_ERROR;

static uint32_t gl_color       = 0;
static uint32_t gl_clear_color = 0;

/*** HeavyGL Common Functions ***/

// --- [ glClear ] ---

void glClear()
{
	fb_fill(backfb, gl_clear_color);
}

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

// --- [ glFillRect ] ---

void glFillRect(float xf, float yf, float widthf, float heightf) {
    int x = (int) xf, y = (int) yf;
    int width = (int) widthf, height = (int) heightf;

    int x_start = x < 0 ? 0 : x;
    int y_start = y < 0 ? 0 : y;
    int x_end = (x + width > backfb->width) ? backfb->width : (x + width);
    int y_end = (y + height > backfb->height) ? backfb->height : (y + height);

    for (int row = y_start; row < y_end; row++) {
        for (int col = x_start; col < x_end; col++) {
            int index = row * backfb->width + col;
            if (index >= 0 && index < backfb->len)
                backfb->pixels[index] = gl_color;
        }
    }
}

// --- [ glFlush ] ---

void glFlush()
{
    fb_copy(frontfb, backfb);
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

/*** HeavyGL Special Functions ***/

void glXSetContext(intptr_t address, int w, int h)
{
    if (frontfb == NULL)
		frontfb = fb_existing(address, w, h);
    
    // Create back buffer version
    backfb = fb_existing((intptr_t)) malloc(w * h * 4), w, h);
}

#endif

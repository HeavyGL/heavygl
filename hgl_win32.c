#ifdef __WIN32__

#include "hgl/HGL.h"
#include "hgl/buffers.h"
#include "hgl/colors.h"

#include <stdint.h>

/* Static variables */
static GLframebuffer * frontfb = NULL;
static GLframebuffer * backfb  = NULL;
static GLframebuffer * fb      = NULL;
static GLerror gl_error = GL_NO_ERROR;

static uint32_t gl_color       = 0;
static uint32_t gl_clear_color = 0;

/*** HeavyGL Common Functions ***/

// --- [ glClear ] ---

void glClear()
{
	fb_fill(fb, gl_clear_color);
}

// --- [ glDisable ] ---

void glDisable(GLfeature cap)
{
    switch (cap)
    {
        case GL_DOUBLEBUFFER:
            fb = frontfb; // Render directly to the front framebuffer
            break;
    }
}

// --- [ glEnable ] ---

void glEnable(GLfeature cap)
{
    switch (cap)
    {
        case GL_DOUBLEBUFFER:
            fb = backfb; // Use back framebuffer to do double buffering
            break;
    }
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
    int x_end = (x + width > fb->width) ? fb->width : (x + width);
    int y_end = (y + height > fb->height) ? fb->height : (y + height);

    for (int row = y_start; row < y_end; row++) {
        for (int col = x_start; col < x_end; col++) {
            int index = row * fb->width + col;
            if (index >= 0 && index < fb->len)
                fb->pixels[index] = gl_color;
        }
    }
}

// --- [ glFlush ] ---

void glFlush()
{
    // If doublebuffering is disabled then we don't need to flush
    if (fb == frontfb)
        return;

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
            return "b1.2.0";
			
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
    backfb = fb_existing((intptr_t) malloc(w * h * 4), w, h);
    glEnable(GL_DOUBLEBUFFER); // Setup doublebuffering (can be disabled later)
}

#endif

#include "HGL/colors.h"

uint32_t ColorRGB_3F(float r, float g, float b) 
{
	int ubr = (int) ((float) r * 255.0);
    int ubg = (int) ((float) g * 255.0);
    int ubb = (int) ((float) b * 255.0);

    return ColorRGB_UB3(ubr, ubg, ubb);
}

uint32_t ColorRGB_UB3(int r, int g, int b)
{
    return (r << 16) + (g << 8) + b;
}
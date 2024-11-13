/*
 * HGL Specification 1.2
 */
#pragma once

#ifndef COLORS_H
#define COLORS_H 1

#include <stdint.h>

/**
 * =================================================================
 * EN: Converts 3 floats to 1 unsigned integer
 * ES: Convierte 3 valores flotantes a un valor entero sin signo
 * =================================================================
 * NOTE: Not specified yet.
 */
uint32_t ColorRGB_3F(float, float, float);

/**
 * =================================================================
 * EN: Converts 3 rgb integers to a single one
 * ES: Convierte 3 enteros rgb a uno solo
 * =================================================================
 * NOTE: Not specified yet.
 */
uint32_t ColorRGB_UB3(int, int, int);

#endif // COLORS_H
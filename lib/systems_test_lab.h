/*
 * SyntaxSculptor
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SYSTEMS_TEST_LAB_H

#include <stdint.h>

/**
 * Returns whether the provided string is a binary string.
 */
int is_binary_str(const char* str);

/**
 * Returns the bit width of a binary string.
 * 
 * Returns 0 if the provided binary string is invalid.
 */
size_t get_bit_width(const char* str);

#endif
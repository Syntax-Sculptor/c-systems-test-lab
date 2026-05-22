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

/**
 * Converts the provided binary string into an unsigned 32-bit integer and writes it
 * to the provided `val`.
 * 
 * This function will only work for binary strings with a width between 1 and 32.
 * 
 * Returns whether the value was successfully written to.
 */
int get_unsigned_value(const char *bin_str, uint32_t* val);

/**
 * Converts the provided binary string into an signed 32-bit integer and writes it
 * to the provided `val`.
 * 
 * This function will only work for binary strings with a width between 1 and 32.
 * 
 * Returns whether the value was successfully written to.
 */
int get_signed_value(const char *bin_str, int32_t* val);

/**
 * Writes the minimum signed value using the given width to the provided `val`.
 * 
 * This function will only work for binary strings with a width between 1 and 32.
 * 
 * Returns whether the value was successfully written to.
 */
int get_t_min(size_t width, int32_t* val);

/**
 * Returns whether the provided width is between 1 - 32. 
 */
int is_valid_width(size_t width);
#endif
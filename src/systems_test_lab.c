/*
 * SyntaxSculptor
 *
 * SPDX-License-Identifier: MIT
 */

#include <string.h>
#include <stdint.h>

#include "systems_test_lab.h"

int is_binary_str(const char* bin_str) {
    if (bin_str == NULL) {
        return 0;
    }

    size_t len = strlen(bin_str);

    if (len == 0) {
        return 0;
    }

    for (size_t i = 0; i < len; i++) {
        if (bin_str[i] != '1' && bin_str[i] != '0') {
            return 0;
        }
    }

    return 1;
}

size_t get_bit_width(const char* bin_str) {
    if (bin_str == NULL || !is_binary_str(bin_str)) {
        return 0;
    }

    return strlen(bin_str);
}

int get_unsigned_value(const char *bin_str, uint32_t* val) {
    size_t bit_width = get_bit_width(bin_str);

    if (
        bin_str == NULL || 
        !is_binary_str(bin_str) || 
        bit_width > 32 || 
        val == NULL
    ) {
        return 0;
    }

    uint32_t final_val = 0;

    for (size_t i = 0; i < bit_width; i++) {
        char bit = bin_str[i];

        if (bit == '1') {
            final_val |= (1U << (bit_width - i - 1));
        }
    }

    *val = final_val;

    return 1;
}

int get_signed_value(const char *bin_str, int32_t* val) {
    if (bin_str == NULL || val == NULL || !is_binary_str(bin_str)) {
        return 0;
    }

    uint32_t uval;
    size_t width = get_bit_width(bin_str);

    if (width > 32 || !get_unsigned_value(bin_str, &uval)) {
        return 0;
    }

    char signbit = bin_str[0];

    if (signbit == '0') {
        *val = (int32_t) uval;
        return 1;
    }

    if (width == 32) {
        // If the width is at its maximum value, shifting it by 32 can cause
        // undefined behavior.
        *val = (int32_t) uval;
    } else {
        uint32_t mask = UINT32_MAX << width;
        uint32_t res = mask | uval;
        *val = (int32_t) res;
    }

    return 1;
}
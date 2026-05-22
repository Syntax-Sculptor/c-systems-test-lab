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
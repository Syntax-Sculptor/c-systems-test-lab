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
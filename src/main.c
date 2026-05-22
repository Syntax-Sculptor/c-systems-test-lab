/*
 * SyntaxSculptor
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "systems_test_lab.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./systems_test_lab <binary string>\n");
        return EXIT_FAILURE;
    }

    char* bin_str = argv[1];

    if (!is_binary_str(bin_str)) {
        printf("Please enter a valid binary string.\n");
        return EXIT_FAILURE;
    }

    size_t width = get_bit_width(bin_str);

    if (!is_valid_width(width)) {
        printf("Please enter a binary string between 1 and 32 bits.\n");
        return EXIT_FAILURE;
    }

    // Reporting

    uint32_t unsigned_val;
    get_unsigned_value(bin_str, &unsigned_val);

    int32_t signed_val;
    get_signed_value(bin_str, &signed_val);

    int32_t t_max;
    get_t_max(width, &t_max);

    int32_t t_min;
    get_t_min(width, &t_min);

    uint32_t u_max;
    get_u_max(width, &u_max);

    printf("Bits:       %s\n", bin_str);
    printf("Width:      %zu\n", width);
    printf("Unsigned:   %u\n", unsigned_val);
    printf("Signed:     %d\n", signed_val);
    printf("TMin:       %d\n", t_min);
    printf("TMax:       %d\n", t_max);
    printf("UMax:       %u\n", u_max);

    return EXIT_SUCCESS;
}
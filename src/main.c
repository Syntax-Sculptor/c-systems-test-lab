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

    // Reporting

    printf("Bits:       %s\n", bin_str);
    printf("Width:      %zu\n", get_bit_width(bin_str));

    return EXIT_SUCCESS;
}
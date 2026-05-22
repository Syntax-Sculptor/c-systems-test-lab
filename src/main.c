/*
 * SyntaxSculptor
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

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

    return EXIT_SUCCESS;
}
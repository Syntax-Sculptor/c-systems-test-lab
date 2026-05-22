/*
 * Syntax-Sculptor
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <stdlib.h>

#include "unity.h"

#include "systems_test_lab.h"

void setUp(void) {
    
}

void tearDown(void) {

}

void test_is_binary_str(void) {
    TEST_ASSERT_TRUE(is_binary_str("1"));
    TEST_ASSERT_TRUE(is_binary_str("0"));
    TEST_ASSERT_TRUE(is_binary_str("10110"));

    TEST_ASSERT_FALSE(is_binary_str(""));
    TEST_ASSERT_FALSE(is_binary_str("102"));
    TEST_ASSERT_FALSE(is_binary_str("1a0"));
    TEST_ASSERT_FALSE(is_binary_str(NULL));
}

void test_get_bit_width(void) {
    TEST_ASSERT_EQUAL_size_t(0, get_bit_width(""));
    TEST_ASSERT_EQUAL_size_t(1, get_bit_width("1"));
    TEST_ASSERT_EQUAL_size_t(4, get_bit_width("0110"));
    TEST_ASSERT_EQUAL_size_t(0, get_bit_width("a1"));
    TEST_ASSERT_EQUAL_size_t(0, get_bit_width("102"));
    TEST_ASSERT_EQUAL_size_t(0, get_bit_width(NULL));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_is_binary_str);
    RUN_TEST(test_get_bit_width);
    
    return UNITY_END();
}
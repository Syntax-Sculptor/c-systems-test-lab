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

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_is_binary_str);
    
    return UNITY_END();
}
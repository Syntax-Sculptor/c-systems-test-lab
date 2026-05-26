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

void test_get_unsigned_val(void) {
    uint32_t res = 0;

    TEST_ASSERT_TRUE(get_unsigned_value("0", &res));
    TEST_ASSERT_EQUAL_UINT32(0, res);

    TEST_ASSERT_TRUE(get_unsigned_value("1", &res));
    TEST_ASSERT_EQUAL_UINT32(1, res);

    TEST_ASSERT_TRUE(get_unsigned_value("10", &res));
    TEST_ASSERT_EQUAL_UINT32(2, res);

    TEST_ASSERT_TRUE(get_unsigned_value("11", &res));
    TEST_ASSERT_EQUAL_UINT32(3, res);

    TEST_ASSERT_TRUE(get_unsigned_value("0110", &res));
    TEST_ASSERT_EQUAL_UINT32(6, res);

    TEST_ASSERT_TRUE(get_unsigned_value("1111", &res));
    TEST_ASSERT_EQUAL_UINT32(15, res);
    TEST_ASSERT_TRUE(get_unsigned_value("1111", &res));
    TEST_ASSERT_EQUAL_UINT32(15, res);

    TEST_ASSERT_TRUE(get_unsigned_value("11111111111111111111111111111111", &res));
    TEST_ASSERT_EQUAL_UINT32(UINT32_MAX, res);

    // Width is over 32 bits which isn't allowed.
    TEST_ASSERT_FALSE(
        get_unsigned_value("111111111111111111111111111111110", &res)
    );

    TEST_ASSERT_FALSE(get_unsigned_value("", &res));
    TEST_ASSERT_FALSE(get_unsigned_value("102", &res));
    TEST_ASSERT_FALSE(get_unsigned_value("10a", &res));
    TEST_ASSERT_FALSE(get_unsigned_value(NULL, &res));
    TEST_ASSERT_FALSE(get_unsigned_value("100", NULL));
}

void test_get_signed_value(void) {
    int32_t res = 0;

    TEST_ASSERT_TRUE(get_signed_value("0", &res));
    TEST_ASSERT_EQUAL_INT32(0, res);

    TEST_ASSERT_TRUE(get_signed_value("1", &res));
    TEST_ASSERT_EQUAL_INT32(-1, res);

    TEST_ASSERT_TRUE(get_signed_value("01", &res));
    TEST_ASSERT_EQUAL_INT32(1, res);

    TEST_ASSERT_TRUE(get_signed_value("10", &res));
    TEST_ASSERT_EQUAL_INT32(-2, res);

    TEST_ASSERT_TRUE(get_signed_value("11", &res));
    TEST_ASSERT_EQUAL_INT32(-1, res);

    TEST_ASSERT_TRUE(get_signed_value("10000000", &res));
    TEST_ASSERT_EQUAL_INT32(-128, res);

    TEST_ASSERT_TRUE(get_signed_value("11111111", &res));
    TEST_ASSERT_EQUAL_INT32(-1, res);

    TEST_ASSERT_TRUE(get_signed_value("11111111111111111111111111111111", &res));
    TEST_ASSERT_EQUAL_INT32(-1, res);

    TEST_ASSERT_TRUE(get_signed_value("01111111111111111111111111111111", &res));
    TEST_ASSERT_EQUAL_INT32(2147483647, res);

    TEST_ASSERT_TRUE(get_signed_value("10000000000000000000000000000000", &res));
    TEST_ASSERT_EQUAL_INT32(-2147483648, res);

    TEST_ASSERT_FALSE(get_signed_value("", &res));
    TEST_ASSERT_FALSE(get_signed_value("102", &res));
    TEST_ASSERT_FALSE(get_signed_value("10a", &res));
    TEST_ASSERT_FALSE(get_signed_value(NULL, &res));
    TEST_ASSERT_FALSE(get_signed_value("100", NULL));
}

void test_get_t_min(void) {
    int32_t res = 0;

    TEST_ASSERT_TRUE(get_t_min(1, &res));
    TEST_ASSERT_EQUAL_INT32(-1, res);

    TEST_ASSERT_TRUE(get_t_min(2, &res));
    TEST_ASSERT_EQUAL_INT32(-2, res);

    TEST_ASSERT_TRUE(get_t_min(4, &res));
    TEST_ASSERT_EQUAL_INT32(-8, res);

    TEST_ASSERT_TRUE(get_t_min(8, &res));
    TEST_ASSERT_EQUAL_INT32(-128, res);

    TEST_ASSERT_TRUE(get_t_min(16, &res));
    TEST_ASSERT_EQUAL_INT32(-32768, res);

    TEST_ASSERT_TRUE(get_t_min(31, &res));
    TEST_ASSERT_EQUAL_INT32(-1073741824, res);

    TEST_ASSERT_TRUE(get_t_min(32, &res));
    TEST_ASSERT_EQUAL_INT32(INT32_MIN, res);

    TEST_ASSERT_FALSE(get_t_min(0, &res));
    TEST_ASSERT_FALSE(get_t_min(33, &res));
    TEST_ASSERT_FALSE(get_t_min(4, NULL));
}

void test_get_t_max(void) {
    int32_t res = 0;

    TEST_ASSERT_TRUE(get_t_max(1, &res));
    TEST_ASSERT_EQUAL_INT32(0, res);

    TEST_ASSERT_TRUE(get_t_max(2, &res));
    TEST_ASSERT_EQUAL_INT32(1, res);

    TEST_ASSERT_TRUE(get_t_max(4, &res));
    TEST_ASSERT_EQUAL_INT32(7, res);

    TEST_ASSERT_TRUE(get_t_max(8, &res));
    TEST_ASSERT_EQUAL_INT32(127, res);

    TEST_ASSERT_TRUE(get_t_max(31, &res));
    TEST_ASSERT_EQUAL_INT32(1073741823, res);

    TEST_ASSERT_TRUE(get_t_max(32, &res));
    TEST_ASSERT_EQUAL_INT32(INT32_MAX, res);

    TEST_ASSERT_FALSE(get_t_max(0, &res));
    TEST_ASSERT_FALSE(get_t_max(33, &res));
    TEST_ASSERT_FALSE(get_t_max(4, NULL));
}

void test_is_valid_width(void) {
    TEST_ASSERT_TRUE(is_valid_width(1));
    TEST_ASSERT_TRUE(is_valid_width(10));
    TEST_ASSERT_TRUE(is_valid_width(32));

    TEST_ASSERT_FALSE(is_valid_width(-5));
    TEST_ASSERT_FALSE(is_valid_width(0));
    TEST_ASSERT_FALSE(is_valid_width(33));
}

void test_get_zero_extended_32(void) {
    uint32_t res = 0;

    TEST_ASSERT_TRUE(get_zero_extended_32("0", &res));
    TEST_ASSERT_EQUAL_UINT32(0x00000000, res);

    TEST_ASSERT_TRUE(get_zero_extended_32("1", &res));
    TEST_ASSERT_EQUAL_UINT32(0x00000001, res);

    TEST_ASSERT_TRUE(get_zero_extended_32("1111", &res));
    TEST_ASSERT_EQUAL_UINT32(0x0000000F, res);

    TEST_ASSERT_TRUE(get_zero_extended_32("1000", &res));
    TEST_ASSERT_EQUAL_UINT32(0x00000008, res);

    TEST_ASSERT_TRUE(get_zero_extended_32("10101010", &res));
    TEST_ASSERT_EQUAL_UINT32(0x000000AA, res);

    TEST_ASSERT_FALSE(get_zero_extended_32("", &res));
    TEST_ASSERT_FALSE(get_zero_extended_32(NULL, &res));
    TEST_ASSERT_FALSE(get_zero_extended_32("102", &res));
    TEST_ASSERT_FALSE(get_zero_extended_32("1", NULL));
    
    // 32-bits
    TEST_ASSERT_FALSE(
        get_zero_extended_32("111111111111111111111111111111111", &res)
    );
}

void test_get_sign_extended_32(void) {
    uint32_t res = 0;

    TEST_ASSERT_TRUE(get_sign_extended_32("0", &res));
    TEST_ASSERT_EQUAL_UINT32(0x00000000, res);

    TEST_ASSERT_TRUE(get_sign_extended_32("1", &res));
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF, res);

    TEST_ASSERT_TRUE(get_sign_extended_32("01", &res));
    TEST_ASSERT_EQUAL_UINT32(0x00000001, res);

    TEST_ASSERT_TRUE(get_sign_extended_32("10", &res));
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE, res);

    TEST_ASSERT_TRUE(get_sign_extended_32("1111", &res));
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF, res);

    TEST_ASSERT_TRUE(get_sign_extended_32("10000000", &res));
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFF80, res);

    TEST_ASSERT_FALSE(get_sign_extended_32("", &res));
    TEST_ASSERT_FALSE(get_sign_extended_32(NULL, &res));
    TEST_ASSERT_FALSE(get_sign_extended_32("102", &res));
    TEST_ASSERT_FALSE(get_sign_extended_32("1", NULL));
    
    // 32-bits
    TEST_ASSERT_FALSE(
        get_zero_extended_32("111111111111111111111111111111111", &res)
    );
}

void test_get_u_max(void) {
    uint32_t res = 0;

    TEST_ASSERT_TRUE(get_u_max(1, &res));
    TEST_ASSERT_EQUAL_UINT32(1, res);

    TEST_ASSERT_TRUE(get_u_max(2, &res));
    TEST_ASSERT_EQUAL_UINT32(3, res);

    TEST_ASSERT_TRUE(get_u_max(4, &res));
    TEST_ASSERT_EQUAL_UINT32(15, res);

    TEST_ASSERT_TRUE(get_u_max(8, &res));
    TEST_ASSERT_EQUAL_UINT32(255, res);

    TEST_ASSERT_TRUE(get_u_max(31, &res));
    TEST_ASSERT_EQUAL_UINT32(2147483647, res);

    TEST_ASSERT_TRUE(get_u_max(32, &res));
    TEST_ASSERT_EQUAL_UINT32(UINT32_MAX, res);

    TEST_ASSERT_FALSE(get_u_max(0, &res));
    TEST_ASSERT_FALSE(get_u_max(33, &res));
    TEST_ASSERT_FALSE(get_u_max(4, NULL));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_is_binary_str);
    RUN_TEST(test_get_bit_width);
    RUN_TEST(test_get_unsigned_val);
    RUN_TEST(test_get_signed_value);
    RUN_TEST(test_is_valid_width);
    RUN_TEST(test_get_t_min);
    RUN_TEST(test_get_t_max);
    RUN_TEST(test_get_u_max);
    RUN_TEST(test_get_sign_extended_32);
    RUN_TEST(test_get_zero_extended_32);
    
    return UNITY_END();
}
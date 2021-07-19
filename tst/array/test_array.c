//
// Created by Mason Morris on 7/18/21.
//
#include "unity/unity.h"
#include "array.h"

void setUp(void) {
    // Blank for now to appease the compiler
}

void tearDown(void) {
    // Blank for now to appease the compiler
}

void test_init_array(void) {
    Array *arr = array_new(4);
    TEST_ASSERT_EQUAL(8, arr->capacity);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_init_array);
    return UNITY_END();
}
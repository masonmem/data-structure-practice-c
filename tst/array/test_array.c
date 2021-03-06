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


void test_array_init(void) {
    // Test init array negative capacity
    Array *arr = array_new(-4);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE, arr->capacity);
    array_destroy(arr);

    // Test init array with 0 capacity
    arr = array_new(0);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE, arr->capacity);
    array_destroy(arr);

    // Test init array with the min capacity border case
    arr = array_new(ARRAY_MIN_INIT_SIZE);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE, arr->capacity);
    array_destroy(arr);

    // Test init array min capacity border case, part 2
    arr = array_new(ARRAY_MIN_INIT_SIZE + 1);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE * ARRAY_GROWTH_RATE, arr->capacity);
    array_destroy(arr);

    // Test init array with a very large capacity
    arr = array_new(300000);

    // Figure out our expected size
    int expectedSize = ARRAY_MIN_INIT_SIZE;
    while (expectedSize < 300000) {
        expectedSize *= ARRAY_GROWTH_RATE;
    }

    TEST_ASSERT_EQUAL(expectedSize, arr->capacity);
    array_destroy(arr);
}


void test_array_upsize(void) {
    Array *arr = array_new(8);
    TEST_ASSERT_EQUAL(8, arr->capacity);
    int initialCapacity = arr->capacity;

    array_upsize(arr);
    TEST_ASSERT_EQUAL(initialCapacity * ARRAY_GROWTH_RATE, arr->capacity);

    array_upsize(arr);
    TEST_ASSERT_EQUAL(initialCapacity * ARRAY_GROWTH_RATE * ARRAY_GROWTH_RATE, arr->capacity);

    array_destroy(arr);
}


void test_array_downsize(void) {
    Array *arr = array_new(ARRAY_MIN_INIT_SIZE * ARRAY_GROWTH_RATE * ARRAY_GROWTH_RATE);
    int initialCapacity = arr->capacity;
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE * ARRAY_GROWTH_RATE * ARRAY_GROWTH_RATE, arr->capacity);

    array_downsize(arr);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE * ARRAY_GROWTH_RATE, arr->capacity);

    array_downsize(arr);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE, arr->capacity);

    // Assert that when we're at the minimum size, we don't continue downsizing.
    array_downsize(arr);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE, arr->capacity);

    array_destroy(arr);
}


void test_array_pop(void) {
    Array *arr = array_new(8);

    array_push(arr, 4);
    array_push(arr, 8);
    array_push(arr, 15);
    array_push(arr, 16);
    array_push(arr, 23);
    array_push(arr, 42);

    int data;
    TEST_ASSERT_TRUE(array_pop(arr, &data));
    TEST_ASSERT_EQUAL(42, data);

    TEST_ASSERT_TRUE(array_pop(arr, &data));
    TEST_ASSERT_EQUAL(23, data);

    TEST_ASSERT_TRUE(array_pop(arr, &data));
    TEST_ASSERT_EQUAL(16, data);

    TEST_ASSERT_TRUE(array_pop(arr, &data));
    TEST_ASSERT_EQUAL(15, data);

    TEST_ASSERT_TRUE(array_pop(arr, &data));
    TEST_ASSERT_EQUAL(8, data);

    TEST_ASSERT_TRUE(array_pop(arr, &data));
    TEST_ASSERT_EQUAL(4, data);

    TEST_ASSERT_FALSE(array_pop(arr, &data));

    array_destroy(arr);
}


void test_array_push(void) {
    Array *arr = array_new(8);

    array_push(arr, 4);
    array_push(arr, 8);
    array_push(arr, 15);
    array_push(arr, 16);
    array_push(arr, 23);
    array_push(arr, 42);

    // Test expected size
    TEST_ASSERT_EQUAL(6, arr->size);

    // Test expected data
    TEST_ASSERT_EQUAL(4, arr->data[0]);
    TEST_ASSERT_EQUAL(8, arr->data[1]);
    TEST_ASSERT_EQUAL(15, arr->data[2]);
    TEST_ASSERT_EQUAL(16, arr->data[3]);
    TEST_ASSERT_EQUAL(23, arr->data[4]);
    TEST_ASSERT_EQUAL(42, arr->data[5]);

    // Test that array properly grows when it hits capacity limit during push operations
    while (arr->size < (ARRAY_MIN_INIT_SIZE * ARRAY_GROWTH_RATE)) {
        array_push(arr, 99);
    }
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE * ARRAY_GROWTH_RATE, arr->capacity);

    array_destroy(arr);
}


void test_array_size(void) {
    Array *arr = array_new(2);
    TEST_ASSERT_EQUAL(0, array_size(arr));

    array_push(arr, 1);
    TEST_ASSERT_EQUAL(1, array_size(arr));

    array_push(arr, 8);
    TEST_ASSERT_EQUAL(2, array_size(arr));

    array_destroy(arr);
}

void test_array_capacity(void) {
    Array *arr = array_new(1);
    TEST_ASSERT_EQUAL(ARRAY_MIN_INIT_SIZE, array_capacity(arr));

    array_destroy(arr);
}

void test_array_print(void) {
    Array *arr = array_new(6);
    array_push(arr, 4);
    array_push(arr, 8);
    array_push(arr, 15);
    array_push(arr, 16);
    array_push(arr, 23);
    array_push(arr, 42);

    char buffer[512];
    FILE *f = fmemopen(buffer, sizeof(buffer), "w");
    array_print(arr, f);
    fclose(f);

    TEST_ASSERT_EQUAL_STRING("Array size: 6\n"
                        "Array capacity: 8\n"
                        "Array contents:\n"
                        "[ 4 ]\n"
                        "[ 8 ]\n"
                        "[ 15 ]\n"
                        "[ 16 ]\n"
                        "[ 23 ]\n"
                        "[ 42 ]\n"
                        ,
                        buffer);

    array_destroy(arr);
}

void test_array_at(void) {
    Array *arr = array_new(6);
    array_push(arr, 4);
    array_push(arr, 8);
    array_push(arr, 15);
    array_push(arr, 16);
    array_push(arr, 23);
    array_push(arr, 42);

    TEST_ASSERT_EQUAL(4, array_at(arr, 0));
    TEST_ASSERT_EQUAL(8, array_at(arr, 1));
    TEST_ASSERT_EQUAL(15, array_at(arr, 2));
    TEST_ASSERT_EQUAL(16, array_at(arr, 3));
    TEST_ASSERT_EQUAL(23, array_at(arr, 4));
    TEST_ASSERT_EQUAL(42, array_at(arr, 5));

    array_destroy(arr);
}


void test_array_is_empty(void) {
    Array *arr = array_new(6);
    TEST_ASSERT_TRUE(array_is_empty(arr));

    array_push(arr, 4);
    TEST_ASSERT_FALSE(array_is_empty(arr));

    array_destroy(arr);
}

void test_array_resize(void) {
    Array *arr = array_new(0);
    array_resize(arr, 3);
    TEST_ASSERT_EQUAL(8, arr->capacity);

    array_resize(arr, 10);
    TEST_ASSERT_EQUAL(16, arr->capacity);

    array_resize(arr, 800);
    TEST_ASSERT_EQUAL(1024, arr->capacity);

    array_resize(arr, 3);
    TEST_ASSERT_EQUAL(8, arr->capacity);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_array_init);
    RUN_TEST(test_array_upsize);
    RUN_TEST(test_array_downsize);
    RUN_TEST(test_array_pop);
    RUN_TEST(test_array_push);
    RUN_TEST(test_array_size);
    RUN_TEST(test_array_capacity);
    RUN_TEST(test_array_print);
    RUN_TEST(test_array_at);
    RUN_TEST(test_array_is_empty);
    RUN_TEST(test_array_resize);
    return UNITY_END();
}
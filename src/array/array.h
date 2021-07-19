//
// Created by Mason Morris on 7/16/21.
//
#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <assert.h>
#include <stdbool.h>

#define ARRAY_GROWTH_RATE 2;
#define ARRAY_MIN_INIT_SIZE 8;

typedef struct ImplementationArray {
    int size;
    int capacity;
    int *data;
} Array;

// Creates a new MArray to accommodate
// the provided capacity
Array *array_new(int capacity);

void array_destroy(Array *arrptr);

// Checks to see if resizing is needed to support the candidate_size
// and resizes to accommodate.

void array_resize_for_size(Array *arrptr, int candidate_size);

// Determines the actual capacity (in terms of the power of growth factor)
// required to accommodate a given capacity.
int array_determine_capacity(int capacity);

// Increases the array size to size determined by growth factor
void array_upsize(Array *arrptr);

// Decreases the array size to size determined by growth factor
void array_downsize(Array *arrptr);

// Returns the number of elements managed in the array.
int array_size(Array *arrptr);

// Appends the given item to the end of the array.
void array_push(Array *arrptr, int item);

// Prints public information about the array for debug purposes.
void array_print(Array *arrptr);

// Returns the actual capacity the array can accommodate.
int array_capacity(Array *arrptr);

// Returns the value stored at the given index.
int array_at(Array *arrptr, int index);

// Returns true if array is empty.
bool array_is_empty(Array *arrptr);

// Inserts the given value at the given index, shifting
// current and trailing elements to the right.
void array_insert(Array *arrptr, int index, int value);

// Prepends the given value to the array, shifting trailing
// elements to the right.
void array_prepend(Array *arrptr, int value);

// Removes the last item from the array and returns its value.
int array_pop(Array *arrptr);

// Deletes the item stored at the given index, shifting trailing
// elements to the left.
void array_delete(Array *arrptr, int index);

// Removes the given value from the array, even if it appears more than once.
void array_remove(Array *arrptr, int value);

// Returns the index of the first occurrence of the given value in the array.
int array_find(Array *arrptr, int value);

// Checks to see if given value is valid for memory, and exits if so
void check_address(void *p);

// tests
void run_all_tests();
void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
void test_resize();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_remove();
void test_find_exists();
void test_find_not_exists();


#endif //C_ARRAY_H

//
// Created by Mason Morris on 7/16/21.
//

#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <assert.h>
#include <stdbool.h>

typedef struct MMImplementationArray {
    int size;
    int capacity;
    int *data;
} MArray;

// Creates a new MArray to accomodate
// the provided capacity
MArray *marray_new(int capacity);
void marray_destroy(MArray *arrptr);

// Checks to see if resizing is needed to support the candidate_size
// and resizes to accommodate.

void marray_resize_for_size(MArray *arrptr, int candidate_size);

// Determines the actual capacity (in terms of the power of growth factor)
// required to accommodate a given capacity.
int marray_determine_capacity(int capacity);

// Increases the array size to size determined by growth factor
void marray_upsize(MArray *arrptr);

// Decreases the array size to size determined by growth factor
void marray_downsize(MArray *arrptr);

// Returns the number of elements managed in the array.
int marray_size(MArray *arrptr);

// Appends the given item to the end of the array.
void marray_push(MArray *arrptr, int item);

// Prints public information about the array for debug purposes.
void marray_print(MArray *arrptr);

// Returns the actual capacity the array can accommodate.
int marray_capacity(MArray *arrptr);

// Returns the value stored at the given index.
int marray_at(MArray *arrptr, int index);

// Returns true if array is empty.
bool marray_is_empty(MArray *arrptr);

// Inserts the given value at the given index, shifting
// current and trailing elements to the right.
void marray_insert(MArray *arrptr, int index, int value);

// Prepends the given value to the array, shifting trailing
// elements to the right.
void marray_prepend(MArray *arrptr, int value);

// Removes the last item from the array and returns its value.
int marray_pop(MArray *arrptr);

// Deletes the item stored at the given index, shifting trailing
// elements to the left.
void marray_delete(MArray *arrptr, int index);

// Removes the given value from the array, even if it appears more than once.
void marray_remove(MArray *arrptr, int value);

// Returns the index of the first occurrence of the given value in the array.
int marray_find(MArray *arrptr, int value);

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

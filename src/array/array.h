//
// Created by Mason Morris on 7/16/21.
//
#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <assert.h>
#include <stdbool.h>

#define ARRAY_GROWTH_RATE 2
#define ARRAY_MIN_INIT_SIZE 8

typedef struct ImplementationArray {
    int size;
    int capacity;
    int *data;
} Array;

// Creates new Array fitting provided capacity
Array *array_new(int capacity);

// Finds the appropriate capacity given the request, based on INIT_SIZE and GROWTH_RATE
int array_capacity_fit(int capacity);

// Destroys Array
void array_destroy(Array *arrptr);

// Increases the array capacity by growth rate.
void array_upsize(Array *arrptr);

// Decreases the array capacity by growth rate. If reduction means truncation of elements,
// capacity remains the same.
void array_downsize(Array *arrptr);

// Returns the number of used elements in the array.
int array_size(Array *arrptr);

// Adds the given item to the end of the array.
void array_push(Array *arrptr, int item);

// Removes the last item from the array. Returns true if successful, false if empty.
// Value stored in value pointer passed to array_pop().
bool array_pop(Array *arrptr, int *value);

void array_print(Array *arrptr);

int array_capacity(Array *arrptr);

int array_at(Array *arrptr, int index);

bool array_is_empty(Array *arrptr);

void array_insert(Array *arrptr, int index, int value);

void array_prepend(Array *arrptr, int value);

void array_delete(Array *arrptr, int index);

void array_remove(Array *arrptr, int value);

int array_find(Array *arrptr, int value);


#endif //C_ARRAY_H

//
// Created by Mason Morris on 7/16/21.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"

Array *array_new(int capacity) {
    Array *arr = malloc(sizeof(Array));
    check_address(arr);

    int trueCapacity = array_determine_capacity(capacity);

    arr->size = 0;
    arr->capacity = trueCapacity;
    arr->data = (int *)malloc(sizeof(int) * trueCapacity);
    check_address(arr->data);

    return arr;
}

void array_upsize(Array *arrptr) {
    // Get the appropriate resizing based on the current capacity
    int newCapacity = array_determine_capacity(arrptr->capacity);

    // Re-allocate the Array's data block according to the determined size
    int *new_data = (int*)realloc(arrptr->data, sizeof(int) * newCapacity);
    check_address(new_data);

    // Update Array pointer to re-sized block's address
    arrptr->data = new_data;

    // Update capacity
    arrptr->capacity = newCapacity;
}


int array_determine_capacity(int capacity) {
    // Initial array cannot be smaller than 1 element
    if (capacity < 1) {
        fprintf(stderr, "ERROR: Cannot initialize array with capacity < 1.");
        exit(EXIT_FAILURE);
    }

    int trueCapacity = ARRAY_MIN_INIT_SIZE;
    while (capacity > trueCapacity) {
        trueCapacity *= ARRAY_GROWTH_RATE;
    }

    return trueCapacity;
}

void check_address(void *p) {
    if (p == NULL) {
        printf("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}


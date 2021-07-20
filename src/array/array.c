//
// Created by Mason Morris on 7/16/21.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"
#include "genutils.h"

Array *array_new(int capacity) {
    // Allocate the Array struct
    Array *arr = malloc(sizeof(Array));
    check_address(arr);

    // Find appropriate sizing for the requested data capacity
    int trueCapacity = array_capacity_fit(capacity);

    // Initialize the object variables and allocate the data member based on the
    // determined capacity.
    arr->size = 0;
    arr->capacity = trueCapacity;
    arr->data = (int *)malloc(sizeof(int) * trueCapacity);
    check_address(arr->data);

    return arr;
}

void array_upsize(Array *arrptr) {
    // An upsize means current capacity * growth rate
    int newCapacity = arrptr->capacity * ARRAY_GROWTH_RATE;

    // Re-allocate the Array's data block according to the determined size
    int *new_data = (int*)realloc(arrptr->data, sizeof(int) * newCapacity);
    check_address(new_data);

    // Update Array pointer to re-sized block's address
    arrptr->data = new_data;

    // Update capacity
    arrptr->capacity = newCapacity;
}

void array_downsize(Array *arrptr) {
    // A downsize is the current capacity divided by the GROWTH_RATE
    int newCapacity = arrptr->capacity / ARRAY_GROWTH_RATE;

    // If the downsize means truncating data, don't do it.
    if (newCapacity < arrptr->size) {
        fprintf(stdout, "INFO: Unable to downsize array, as it would lead to truncation.\n");
        return;
    }
    else if (newCapacity < ARRAY_MIN_INIT_SIZE) {
        fprintf(stdout, "INFO: Unable to downsize array, already at minimum size.\n");
        return;
    }

    // Re-allocate the array to the new downsized length
    int *new_data = (int*) realloc(arrptr->data, sizeof(int) * newCapacity);
    check_address(new_data);

    // Swap the pointer
    arrptr->capacity = newCapacity;
    arrptr->data = new_data;
}


int array_capacity_fit(int capacity) {
    // Figure out the appropriate size. The array grows based on the GROWTH_RATE.
    // The first sizing that fits the request will be returned.
    int trueCapacity = ARRAY_MIN_INIT_SIZE;
    while (capacity > trueCapacity) {
        trueCapacity *= ARRAY_GROWTH_RATE;
    }

    return trueCapacity;
}

void array_destroy(Array *arrptr) {
    if (arrptr == NULL) {
        // Not necessarily a failure state... Try to keep going.
        debug("INFO: array_destroy(): Tried to free Array pointer that was null.");
        return;
    }

    // Free the Array's data member
    if (arrptr->data) {
        free(arrptr->data);
    }

    // Free the Array object itself
    free(arrptr);
    arrptr = NULL;
}

int array_size(Array *arrptr) {
    return arrptr->size;
}

void array_push(Array *arrptr, int item) {
    // Because 0-indexed, size is current element + 1
    int insertIdx = arrptr->size;

    // If new element will take us over capacity, resize up
    if ((insertIdx + 1) > arrptr->capacity) {
        array_upsize(arrptr);
    }

    *(arrptr->data + insertIdx) = item;
    arrptr->size++;
}

bool array_pop(Array *arrptr, int *value) {
    if (arrptr->size < 1) {
        fprintf(stdout, "INFO: Unable to pop item off Array. Array is empty.\n");
        return false;
    }

    // Last element is at size - 1 because array is 0-indexed. Update passed value by pointer
    int index = arrptr->size - 1;
    *value = *(arrptr->data + index);

    // Clear data
    arrptr->data[index] = 0;
    arrptr->size--;

    return true;
}

void array_print(Array *arrptr, FILE *fptr) {
    if (fptr == NULL) {
        fprintf(stderr, "ERROR: Could not print. File or stream does not exist.");
    }
    if (arrptr == NULL) {
        fprintf(fptr, "Array: NULL\n");
        return;
    }

    else {
        fprintf(fptr, "Array size: %d\n", arrptr->size);
        fprintf(fptr, "Array capacity: %d\n", arrptr->capacity);
        fprintf(fptr, "Array contents:\n");
        for (int i = 0; i < arrptr->size; i++) {
            fprintf(fptr, "[ %d ]\n", *(arrptr->data + i));
        }
    }
}

int array_capacity(Array *arrptr) {
    return arrptr->capacity;
}

int array_at(Array *arrptr, int index) {
    if (index < 0 || index >= arrptr->size) {
        fprintf(stderr, "ERROR: Unable to fetch data at index %d. Invalid index.", index);
    }
    return *(arrptr->data + index);
}

bool array_is_empty(Array *arrptr) {
    if (arrptr == NULL) {
        fprintf(stderr, "ERROR: Array is uninitialized while trying to check if empty.");
        return true;
    }
    return arrptr->size < 1;
}

void array_insert(Array *arrptr, int index, int value) {

}

void array_resize(Array *arrptr, int neededCapacity) {
    if (arrptr == NULL) {
        fprintf(stderr, "ERROR: Cannot resize uninitialized Array.");
        return;
    }

    if (arrptr->capacity == neededCapacity) {   // Array's current capacity fits. No need to resize.
        return;
    }
    else if (arrptr->capacity < neededCapacity) {   // Array's current capacity is too small. Upsize until it fits.
        while (arrptr->capacity < neededCapacity) {
            array_upsize(arrptr);
        }
    }
    else {  // Array's current capacity is bigger than necessary. Downsize.
        while ( ((arrptr->capacity / ARRAY_GROWTH_RATE) >= arrptr->size) && ((arrptr->capacity / ARRAY_GROWTH_RATE) >= neededCapacity)
            && arrptr->capacity > ARRAY_MIN_INIT_SIZE )
        {
            array_downsize(arrptr);
        }
    }
}





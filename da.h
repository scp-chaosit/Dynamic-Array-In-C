#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
    // length of an array
    long length;

    // array
    void **array;

    // function pointers
    void (*setLength)(void **array, long *length, long newLength);
    void (*allocateArr)(void **array, long length);
} array_t;

// data types: char, short, int, long, long long, float, double
array_t *da_constructor (long n);
void da_setLength (void **array, long *length, long newLength);
void da_allocateArr (void **array, long length);
void da_freeArray (array_t *arr);

// sets everything up; allocates an array (no data will be written there
array_t *da_constructor (long n) {
    array_t *arr = (array_t *)malloc (sizeof (array_t));

    if (n < 0)
        n = ~n+1;

    // length
    arr->length = n;

    // allocation of an array
    arr->array = (void **)malloc (sizeof (void *) * arr->length);

    // setting up function pointers
    arr->setLength = da_setLength;
    arr->allocateArr = da_allocateArr;

    return arr;
}

// will change the length of an array; reallocates an array (with data saving or not)
void da_setLength (void **array, long *length, long newLength) {
    if (newLength <= 0)
        newLength = ~newLength+1;
    // changing length
    *length = newLength;
}

// allocates bytes for an array (no data will be left)
void da_allocateArr (void **array, long length) {
    if (length <= 0)
        length = ~length+1;

    array = (void **)malloc (length * sizeof (void*));
}

void da_freeArray (array_t *arr) {
    if (arr == NULL)
        return;

    free (arr);
    arr = NULL;
}

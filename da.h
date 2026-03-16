#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
    // length of an array
    long length;

    // array
    void **array;
} array_t;

array_t *da_constructor (long n);
void da_setLength (array_t *arr, long newLength);
void da_allocateArr (array_t *arr);
void da_freeArray (array_t *arr);

// sets everything up; allocates an array (no data will be written there)
array_t *da_constructor (long n) {
    array_t *arr = (array_t *)malloc (sizeof (array_t));

    if (n < 0)
        n = ~n+1;

    // length
    arr->length = n;

    // allocation of an array
    arr->array = (void **)malloc (sizeof (void*) * arr->length);

    return arr;
}

void da_setLength (array_t *arr, long newLength) {
    if (newLength < 0 || newLength == 0)
        return;

    arr->length = newLength;

    da_allocateArr(arr);
}

// allocates bytes for an array (no data will be left)
void da_allocateArr (array_t *arr) {
    free (arr->array);

    arr->array = (void **)malloc (sizeof (void*) * arr->length);
}

void da_freeArray (array_t *arr) {
    if (arr == NULL)
        return;

    free (arr);
    arr = NULL;
}

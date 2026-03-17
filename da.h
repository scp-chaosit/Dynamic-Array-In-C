#include <stddef.h>
#include <stdlib.h>

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

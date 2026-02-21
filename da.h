#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CHAR, SHORT, INT,
    LONG, LONG_LONG,
    FLOAT, DOUBLE,
    _NULL
} DataType;

typedef struct Array {
    // storing a data type
    DataType type, prevType;

    // arrays
    union {
        char *charArray;
        short *shortArray;
        int *intArray;
        long *longArray;
        long long *llArray;
        float *floatArray;
        double *doubleArray;
    } data;

    // length of an array
    long length;
} array_t;

// data types: char, short, int, long, long long, float, double
array_t *da_constructor (long n, const char *dataType);
array_t *da_setDataType (array_t *arr, const char *dataType);
array_t *da_allocateArr (array_t *arr);
array_t *da_setLength (array_t *arr, long n);
void da_freeArray (array_t *arr);

// sets everything up; allocates an array of type dataType
array_t *da_constructor (long n, const char *dataType) {
    array_t *arr = (array_t *)malloc (sizeof (array_t));

    if (n < 0)
        n = ~n+1;

    // length
    arr->length = n;

    // data type setting
    arr = da_setDataType (arr, dataType);
    arr->prevType = _NULL;

    // allocation of an array
    arr = da_allocateArr (arr);

    return arr;
}


// sets data type on it's own, with no need to recreate a pointer; realloctes array
array_t *da_setDataType (array_t *arr, const char *dataType) {
    if (arr == NULL)
        return arr;

    if (strcmp (dataType, "char") == 0) {
        arr->prevType = arr->type;
        arr->type = CHAR;
    } else if (strcmp (dataType, "short") == 0) {
        arr->prevType = arr->type;
        arr->type = SHORT;
    } else if (strcmp (dataType, "int") == 0) {
        arr->prevType = arr->type;
        arr->type = INT;
    } else if (strcmp (dataType, "long") == 0) {
        arr->prevType = arr->type;
        arr->type = LONG;
    } else if (strcmp (dataType, "long long") == 0) {
        arr->prevType = arr->type;
        arr->type = LONG_LONG;
    } else if (strcmp (dataType, "float") == 0) {
        arr->prevType = arr->type;
        arr->type = FLOAT;
    } else if (strcmp (dataType, "double") == 0) {
        arr->prevType = arr->type;
        arr->type = DOUBLE;
    }

    arr = da_allocateArr (arr);

    return arr;
}

// allocates bytes for an array (matching specific data type)
array_t *da_allocateArr (array_t *arr) {
    if (arr == NULL)
        return arr;

    da_freeArray (arr);

    switch (arr->type) {
        case CHAR:
            arr->data.charArray = (char *)malloc (arr->length * sizeof (char));
            break;

        case SHORT:
            arr->data.shortArray = (short *)malloc (arr->length * sizeof (short));
            break;

        case INT:
            arr->data.intArray = (int *)malloc (arr->length * sizeof (int));
            break;

        case LONG:
            arr->data.longArray = (long *)malloc (arr->length * sizeof (long));
            break;

        case LONG_LONG:
            arr->data.llArray = (long long *)malloc (arr->length * sizeof (long long));
            break;

        case FLOAT:
            arr->data.floatArray = (float *)malloc (arr->length * sizeof (float));
            break;

        case DOUBLE:
            arr->data.doubleArray = (double *)malloc (arr->length * sizeof (double));
            break;

        case _NULL:
            break;
    }

    return arr;
}

// will change the length of an array; REALLOCATES AN ARRAY
array_t *da_setLength (array_t *arr, long n) {
    if (arr == NULL)
        return arr;

    if (n < 0)
        n = ~n+1;

    // changing length
    arr->length = n;
    
    // reallocating an array
    da_allocateArr (arr);

    return arr;
}

void da_freeArray (array_t *arr) {
    switch (arr->prevType) {
        case CHAR:
            free ((void *)arr->data.charArray);
            break;

        case SHORT:
            free ((void *)arr->data.shortArray);
            break;

        case INT:
            free ((void *)arr->data.intArray);
            break;

        case LONG:
            free ((void *)arr->data.longArray);
            break;

        case LONG_LONG:
            free ((void *)arr->data.llArray);
            break;

        case FLOAT:
            free ((void *)arr->data.floatArray);
            break;

        case DOUBLE:
            free ((void *)arr->data.doubleArray);
            break;

        case _NULL:
            break;
    }
}

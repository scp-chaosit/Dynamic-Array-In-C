#include <stdlib.h>
#include <stddef.h>

typedef struct {
        size_t count, capacity;
} Header;

#define da_push(arr, el) do {                                                        \
        if(arr == NULL) { Header* hdr = malloc(sizeof(*(arr)) * 2 + sizeof(Header)); \
                hdr->count = 0; hdr->capacity = 2; arr = (void*)(hdr + 1); }         \
        Header* hdr = (Header*)(arr) - 1;                                            \
        if(hdr->count >= hdr->capacity) { hdr->capacity *= 2;                        \
                hdr = realloc(hdr, sizeof(*(arr)) * hdr->capacity + sizeof(Header)); \
                (arr) = (void*)(hdr + 1); }                                          \
        (arr)[hdr->count++] = (el);                                                  \
} while(0)

#define da_pop(arr) do {                          \
        if(arr != NULL) {                         \
                Header* hdr = (Header*)(arr) - 1; \
                --hdr->count;                     \
        }                                         \
} while(0)

#define da_length(arr) (((Header*)(arr)) - 1)->count

#define da_free(arr) free((Header*)(arr) - 1)

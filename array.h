#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define ARRAY_INITIAL_CAPACITY 16

#define array(T, a) (T *)array_init(sizeof(T), ARRAY_INITIAL_CAPACITY, a)

#define array_header(a) ((Array_Header *)(a) - 1)
#define array_cap(a) (array_header(a)->cap)
#define array_len(a) (array_header(a)->len)

#define array_remove(a, i) do { \
    Array_Header *h = array_header(a); \
    if (i == h->len - 1) { \
        h->len -= 1; \
    } else if (h->len > 1) { \
        void *ptr = &a[i]; \
        void *last = &a[h->len - 1]; \
        h->len -= 1; \
        memcpy(ptr, last, sizeof(*a)); \
    } \
} while(0);

#define array_append(a, v) ( \
    (a) = array_ensure_capacity(a, 1, sizeof(v)), \
    (a)[array_header(a)->len] = (v), \
    (a)[array_header(a)->len++])

typedef struct {
    void *(*alloc)(size_t bytes);
    void (*free)(size_t bytes, void *ptr);
} Allocator;

typedef struct {
    size_t cap;
    size_t len;
    Allocator *a;
} Array_Header;

void *array_init(size_t item_size, size_t cap, Allocator *a);
void *array_ensure_capacity(void *a, size_t item_count, size_t item_size);

#endif

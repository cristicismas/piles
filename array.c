#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"

void *array_init(size_t item_size, size_t cap, Allocator *a) {
    void *ptr = 0;

    size_t size = item_size * cap + sizeof(Array_Header);
    Array_Header *h = (Array_Header*)a->alloc(size);

    if (h) {
        h->cap = cap;
        h->len = 0;
        h->a = a;
        ptr = h + 1;
    }

    return ptr;
}

void *array_ensure_capacity(void *a, size_t item_count, size_t item_size) {
    Array_Header *h = array_header(a);
    size_t desired_capacity = h->len + item_count;

    if (h->cap < desired_capacity) {
        size_t new_capacity = h->cap * 2;

        while (new_capacity < desired_capacity) {
            new_capacity *= 2;
        }

        size_t new_size = sizeof(Array_Header) + new_capacity * item_size;

        Array_Header *new_h = (Array_Header*)h->a->alloc(new_size);

        if (new_h) {
            size_t old_size = sizeof(*h) + h->len * item_size;
            memcpy(new_h, h, old_size);

            if (h->a->free) {
                h->a->free(old_size, h);
            }

            new_h->cap = new_capacity;
            h = new_h + 1;
        } else {
            h = 0;
        }
    } else {
        h += 1;
    }

    return h;
}


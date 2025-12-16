#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"

void *my_alloc(size_t bytes) {
    return malloc(bytes);
}

void my_free(size_t bytes, void *ptr) {
    (void)bytes;
    free(ptr);
}

int main() {
    char *buf[30];
    Allocator alloc = {
        .free = my_free,
        .alloc = my_alloc,
    };

    int* test = array(int, &alloc);

    for (size_t i = 0; i < 100; i++) {
        array_append(test, i);
    }
    for (size_t i = 0; i < 100; i++) {
        printf("int: %d\n", test[i]);
    }

    printf("Hello world!\n");

    return 0;
}

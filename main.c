#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#include "./raylib/src/raylib.h"

void *my_alloc(size_t bytes) {
    return malloc(bytes);
}

void my_free(size_t bytes, void *ptr) {
    (void)bytes;
    free(ptr);
}

int main() {
    Allocator alloc = {
        .free = my_free,
        .alloc = my_alloc,
    };

    int* test = array(int, &alloc);

    printf("Hello world!\n");

    const int width = 1920;
    const int height = 1080;

    InitWindow(width, height, "Piles");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        Color BG_COLOR = {19, 20, 29, 1};
        ClearBackground(BG_COLOR);
        DrawText("Piles", 190, 200, 200, RAYWHITE);

        EndDrawing();
    }


    CloseWindow();

    return 0;
}

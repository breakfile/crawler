#include "box.h"
#include <raylib.h>
#include <string.h>

int main() {
    InitWindow(400, 300, "engine");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        toupdate();

        BeginDrawing();
        ClearBackground(BLACK);

        todraw();

        EndDrawing();
    }

    return 0;
}

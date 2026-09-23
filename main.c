#include "box.h"
#include <raylib.h>

int main() {
    InitWindow(400, 300, "engine");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        toupdate();

        BeginDrawing();
        ClearBackground(RED);

        todraw();

        EndDrawing();
    }

    return 0;
}

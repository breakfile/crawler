#include "box.h"
#include "menu.h"
#include <raylib.h>
#include "zwait.h"

int main() {
    InitWindow(800, 600, "engine");
    SetTargetFPS(60);

    RenderTexture r_HQDS = LoadRenderTexture(400, 300);

    while (!WindowShouldClose()) {
    	msupdate();
     	waitforz();
        toupdate();

        BeginTextureMode(r_HQDS);
        ClearBackground(RED);

        msdraw();
        todraw();

        EndTextureMode();

        BeginDrawing();
        DrawTexturePro(r_HQDS.texture, (Rectangle){0,0,400,-300}, (Rectangle){0,0,800,600}, (Vector2){0,0}, 0, WHITE);
        EndDrawing();
    }

    return 0;
}

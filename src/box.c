#include "zwait.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <raylib.h>

static int vchars = 0;
static int frames = 0;
static char typing[1024] = "";
static void (*callback)();

static Font font;
static Texture t;

void toclear() {
    vchars = 0;
    frames = 0;
    typing[0] = '\0';
    callback = NULL;
}

void typeoutf(void (*ncallback)(), const char *format, ...) {
    font = LoadFont("unifont.otf");
    t = LoadTexture("dnext.png");

    toclear();

    va_list list;
    va_start(list, format);

    vsnprintf(typing, sizeof(typing), format, list);

    va_end(list);

    callback = ncallback;
}

void toupdate() {
    if (vchars > strlen(typing)) return;
    if (++frames > 3) {
        if (++vchars > strlen(typing)) {
       		setz(callback);
        }
    }
}

void todraw() {
    char buffer[1024];
    memcpy(buffer, typing, vchars);
    buffer[vchars] = '\0';

    if (typing[0] != '\0') {
        DrawRectangle(8, 8, 384, 52, WHITE);
        DrawRectangle(9, 9, 382, 50, BLACK);
    }

    DrawTextEx(font, buffer, (Vector2){16, 16}, 16, 0, WHITE);

    if (vchars >= strlen(typing) && strlen(typing) != 0) {
    	DrawTexture(t, 370, 44, WHITE);
    }
}

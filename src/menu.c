#include "menu.h"
#include <string.h>
#include <raylib.h>

static Menu mstack[16] = {};
static int mssize = 0;
static Font font;

void mstack_push(Menu menu) {
	font = LoadFont("unifont.otf");
	mstack[mssize++] = menu;
}

void mstack_pop() {
	mssize--;
}

void msupdate() {
	Menu *m;
	if (mssize > -1) m = &mstack[mssize-1];
	if (!m) return;


	if (IsKeyPressed(KEY_X))
		if (m->pop_on_x) mstack_pop();
	if (IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP))
		if (m->sel-1 != -1) m->sel--;
	if (IsKeyPressed(KEY_DOWN) || IsKeyPressedRepeat(KEY_DOWN)) {
		int size = 0;
		for (int i = 0; strcmp(m->buttons[i], "__END_MENU__"); i++) {
			size++;
		}
		if (m->sel+1 != size) m->sel++;
	}
}

void msdraw() {
	for (int i = 0; i < mssize; i++) {
		int io = (8+(8*i));
		DrawRectangle(io, io, mstack[i].w, mstack[i].h, WHITE);
		DrawRectangle(io+1, io+1, mstack[i].w-2, mstack[i].h-2, BLACK);
		for (int v = 0; strcmp(mstack[i].buttons[v], "__END_MENU__"); v++) {
			DrawTextEx(font, mstack[i].buttons[v], (Vector2){io+8, (io+8)+(16*v)}, 16, 0, v == mstack[i].sel ? YELLOW : WHITE);
		}
	}
}

#include "menu.h"
#include <string.h>
#include <raylib.h>

static Menu mstack[16] = {};
static int mssize = 0;
static Font font;
static Font sfont;

void drawpanel(int x, int y, int w, int h) {
	DrawRectangle(x-1, y-1, w+2, h+2, BLACK);
	DrawRectangle(x, y, w, h, WHITE);
	DrawRectangle(x+1, y+1, w-(1*2), h-(1*2), LIGHTGRAY);
	DrawRectangle(x+2, y+2, w-(2*2), h-(2*2), GRAY);
	DrawRectangle(x+3, y+3, w-(3*2), h-(3*2), BLACK);
}

void mstack_push(Menu menu) {
	font = LoadFont("unifont.otf");
	sfont = LoadFont("small.ttf");
	mstack[mssize++] = menu;
}

void mstack_pop() {
	mssize--;
}

void mstack_clear() {
	mssize = 0;
}

void msupdate() {
	Menu *m;
	if (mssize > -1) m = &mstack[mssize-1];
	if (mssize == 0) return;

	if (IsKeyPressed(KEY_X))
		if (m->pop_on_x) mstack_pop();
	if (IsKeyPressed(KEY_Z))
		if (m->on_z) m->on_z(m);
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
		drawpanel(io, io, mstack[i].w, mstack[i].h);
		DrawRectangle(io+5, io, MeasureTextEx(sfont, mstack[i].title, 8, 0).x+1, 8, BLACK);
		DrawTextEx(sfont, mstack[i].title, (Vector2){io+6, io}, 8, 0, WHITE);
		for (int v = 0; strcmp(mstack[i].buttons[v], "__END_MENU__"); v++) {
			DrawTextEx(font, mstack[i].buttons[v], (Vector2){io+8, (io+8)+(16*v)}, 16, 0, v == mstack[i].sel ? ( i == mssize-1 ? YELLOW : GREEN ) : WHITE);
		}
	}
}

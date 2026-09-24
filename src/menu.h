#pragma once
#include <stdbool.h>

typedef struct menu {
	char *title;
	int w, h, sel;
	bool pop_on_x;
	char buttons[16][32];
	void (*on_z)(struct menu*);
} Menu;

void drawpanel(int x, int y, int w, int h);
void mstack_push(Menu menu);
void mstack_pop();
void mstack_clear();
void msupdate();
void msdraw();

#pragma once
#include <stdbool.h>

typedef struct {
	int w, h, sel;
	bool pop_on_x;
	char buttons[16][32];
} Menu;

void mstack_push(Menu menu);
void mstack_pop();
void msupdate();
void msdraw();

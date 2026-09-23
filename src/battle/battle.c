#include "battle/battle.h"
#include "box.h"
#include "menu.h"

static void pushbc();

static void on_z(Menu *menu) {
	if (menu->sel == 0) {
		mstack_pop();
		typeoutf(pushbc, "> %s swung\n  the %s!", "Player", "Cheese Knife");
	}
	else if (menu->sel == 1) {
		mstack_pop();
		typeoutf(pushbc, "> %s has\n  no magic.", "Player");
	}
	else if (menu->sel == 2) {
		mstack_pop();
		typeoutf(pushbc, "> You have no items.");
	}
}

const Menu BATTLE_COMMAND = {
	.w = 64,
	.h = 96,
	.on_z = on_z,
	.pop_on_x = false,
	.sel = 0,
	.buttons = {
		"FIGHT",
		"SKILL",
		"ITEM",
		"MOVE",
		"NEXT",
		"__END_MENU__"
	}
};

static void pushbc() {
	toclear();
	mstack_push(BATTLE_COMMAND);
}

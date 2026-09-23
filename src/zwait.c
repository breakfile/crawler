#include "zwait.h"
#include <raylib.h>
#include <string.h>

static void (*callback)();

void waitforz() {
	if (IsKeyPressed(KEY_Z)) {
		if (callback) callback();
		callback = NULL;
	}
}

void setz(void (*ncallback)()) {
	callback = ncallback;
}

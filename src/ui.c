#include "setup.h"

void drawBox(App* app, int x, int y, int w, int h){
	int ix, iy;
	int truew = w - 1;
	int trueh = h;


	drawUTF8(WALL_TOP_LEFT, x, y, app);						// TOP LEFT
	drawUTF8(WALL_TOP_RIGHT, x + truew, y, app);			// TOP RIGHT
	drawUTF8(WALL_BOTTOM_LEFT, x, y + trueh, app);			// BOTTOM LEFT
	drawUTF8(WALL_BOTTOM_RIGHT, x + truew, y + trueh, app);	// BOTTOM RIGHT

	for (ix = 1; ix < truew; ix++){
		drawUTF8(WALL_HORIZONTAL, x + ix, y, app);			// TOP
		drawUTF8(WALL_HORIZONTAL, x + ix, y + trueh, app);	// BOTTOM
	}

	for (iy = 1; iy < trueh; iy++){
		drawUTF8(WALL_VERTICAL, x, y + iy, app);			// LEFT
		drawUTF8(WALL_VERTICAL, x + truew, y + iy, app);			// RIGHT
	}
}
#include "setup.h"

// Panels
Panel logPanel = {
	LEFT_PANEL_WIDTH, 
	VIRTUAL_SCREEN_HEIGHT - LOG_PANEL_HEIGHT, 
	LOG_PANEL_WIDTH, LOG_PANEL_HEIGHT
};

Panel leftPanel = {0, 0, LEFT_PANEL_WIDTH, VIRTUAL_SCREEN_HEIGHT};

Panel rightPanel = {
	VIRTUAL_SCREEN_WIDTH - RIGHT_PANEL_WIDTH, 0,
	RIGHT_PANEL_WIDTH, VIRTUAL_SCREEN_HEIGHT
};

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
		drawUTF8(WALL_VERTICAL, x + truew, y + iy, app);	// RIGHT
	}
}

void drawPanel(App* app, Panel panel){
	int ix, iy;
	int truew = panel.w - 1;
	int trueh = panel.h;


	drawUTF8(WALL_TOP_LEFT, panel.x, panel.y, app);						// TOP LEFT
	drawUTF8(WALL_TOP_RIGHT, panel.x + truew, panel.y, app);			// TOP RIGHT
	drawUTF8(WALL_BOTTOM_LEFT, panel.x, panel.y + trueh, app);			// BOTTOM LEFT
	drawUTF8(WALL_BOTTOM_RIGHT, panel.x + truew, panel.y + trueh, app);	// BOTTOM RIGHT

	for (ix = 1; ix < truew; ix++){
		drawUTF8(WALL_HORIZONTAL, panel.x + ix, panel.y, app);			// TOP
		drawUTF8(WALL_HORIZONTAL, panel.x + ix, panel.y + trueh, app);	// BOTTOM
	}

	for (iy = 1; iy < trueh; iy++){
		drawUTF8(WALL_VERTICAL, panel.x, panel.y + iy, app);			// LEFT
		drawUTF8(WALL_VERTICAL, panel.x + truew, panel.y + iy, app);	// RIGHT
	}
}
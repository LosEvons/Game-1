#include "setup.h"

void drawScreenEdges(App* app){
	int x, y;

	// Corners
	drawUTF8(WALL_TOP_LEFT, 0, 0, app); // Left top
	drawUTF8(WALL_BOTTOM_LEFT, 0, SCREEN_HEIGHT - TILE_HEIGHT, app); // Left bottom
	drawUTF8(WALL_TOP_RIGHT, SCREEN_WIDTH - TILE_WIDTH, 0, app); // Right top
	drawUTF8(WALL_BOTTOM_RIGHT, SCREEN_WIDTH - TILE_WIDTH, SCREEN_HEIGHT - TILE_HEIGHT, app); // Right bottom
	
	for (x = TILE_WIDTH; x < SCREEN_WIDTH - TILE_WIDTH; x += TILE_WIDTH){
		drawUTF8(WALL_HORIZONTAL, x, 0, app);
		drawUTF8(WALL_HORIZONTAL, x, SCREEN_HEIGHT - TILE_HEIGHT, app);
	}

	for (y = TILE_HEIGHT; y < SCREEN_HEIGHT - TILE_HEIGHT; y += TILE_HEIGHT){
		drawUTF8(WALL_VERTICAL, 0, y, app);
		drawUTF8(WALL_VERTICAL, SCREEN_WIDTH - TILE_WIDTH, y, app);
	}
}

void drawLeftPanel(App* app){
	int x, y;

	// Corners
	drawUTF8(WALL_TOP_LEFT, 0, 0, app); // Left top
	drawUTF8(WALL_BOTTOM_LEFT, 0, SCREEN_HEIGHT - TILE_HEIGHT, app); // Left bottom
	drawUTF8(WALL_TOP_RIGHT, LEFT_PANEL_WIDTH - TILE_WIDTH, 0, app); // Right top
	drawUTF8(WALL_BOTTOM_RIGHT, LEFT_PANEL_WIDTH - TILE_WIDTH, SCREEN_HEIGHT - TILE_HEIGHT, app); // Right bottom
	
	for (x = TILE_WIDTH; x < LEFT_PANEL_WIDTH - TILE_WIDTH; x += TILE_WIDTH){
		drawUTF8(WALL_HORIZONTAL, x, 0, app);
		drawUTF8(WALL_HORIZONTAL, x, SCREEN_HEIGHT - TILE_HEIGHT, app);
	}

	for (y = TILE_HEIGHT; y < SCREEN_HEIGHT - TILE_HEIGHT; y += TILE_HEIGHT){
		drawUTF8(WALL_VERTICAL, 0, y, app);
		drawUTF8(WALL_VERTICAL, LEFT_PANEL_WIDTH - TILE_WIDTH, y, app);
	}
}
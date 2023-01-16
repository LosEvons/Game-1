#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include "setup.h"

/* Screen */
#define SCREEN_WIDTH 	1280
#define SCREEN_HEIGHT 	720

/* Tiles */
#define TILE_SIZE 	 	24
#define TILE_HEIGHT 	TILE_SIZE
#define TILE_WIDTH 		TILE_SIZE / 2

/* Map */
#define LEVEL_WIDTH		(SCREEN_WIDTH / 2)
#define LEVEL_HEIGHT 	(SCREEN_HEIGHT / 2)
#define LEVEL_X_OFFSET 	(LEFT_PANEL_WIDTH + TILE_WIDTH)
#define LEVEL_Y_OFFSET	(TILE_HEIGHT)

/* UI */
#define LEFT_PANEL_WIDTH	(SCREEN_WIDTH / 4)
#define RIGHT_PANEL_WIDTH 	(SCREEN_WIDTH / 4)
#define LOG_PANEL_WIDHT		(SCREEN_WIDTH - LEFT_PANEL_WIDTH - RIGHT_PANEL_WIDTH)
#define LOG_PANEL_HEIGHT 	(SCREEN_HEIGHT / 5)

/* Characters */

#define WALL_VERTICAL		"║"
#define WALL_HORIZONTAL		"═"
#define WALL_BOTTOM_RIGHT	"╝"
#define WALL_BOTTOM_LEFT	"╚"
#define WALL_TOP_RIGHT		"╗"
#define WALL_TOP_LEFT		"╔"


/*
#define WALL_VERTICAL		"+"
#define WALL_HORIZONTAL		"+"
#define WALL_BOTTOM_RIGHT	"+"
#define WALL_BOTTOM_LEFT	"+"
#define WALL_TOP_RIGHT		"+"
#define WALL_TOP_LEFT		"+"
*/

#endif
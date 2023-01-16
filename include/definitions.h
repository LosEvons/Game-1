#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include "setup.h"

/* Screen */
#define SCREEN_WIDTH 	1280
#define SCREEN_HEIGHT 	720

/* Tiles */
#define TILE_SIZE 	 	32
#define TILE_HEIGHT 	TILE_SIZE
#define TILE_WIDTH 		(TILE_SIZE / 2)

/* Virtual Screen */
#define VIRTUAL_SCREEN_WIDTH	(SCREEN_WIDTH / TILE_WIDTH)		//Virtual coordinate
#define VIRTUAL_SCREEN_HEIGHT 	(SCREEN_HEIGHT / TILE_HEIGHT)	//Virtual coordinate

/* Map */
#define LEVEL_WIDTH		((VIRTUAL_SCREEN_WIDTH / 2) - 2)				//Virtual coordinate (-2 padding for sides)
#define LEVEL_HEIGHT 	((VIRTUAL_SCREEN_HEIGHT - LOG_PANEL_HEIGHT) - 2)//Virtual coordinate (-2 padding for sides)
#define LEVEL_X_OFFSET 	(LEFT_PANEL_WIDTH + 1)							//Virtual coordinate
#define LEVEL_Y_OFFSET	1 												//Virtual coordinate

/* UI */
#define LEFT_PANEL_WIDTH	(VIRTUAL_SCREEN_WIDTH / 4)					//Virtual coordinate
#define RIGHT_PANEL_WIDTH 	(VIRTUAL_SCREEN_WIDTH / 4)					//Virtual coordinate

#define LOG_PANEL_WIDTH		(VIRTUAL_SCREEN_WIDTH - LEFT_PANEL_WIDTH - RIGHT_PANEL_WIDTH)	//Virtual coordinate
#define LOG_PANEL_HEIGHT 	(VIRTUAL_SCREEN_HEIGHT / 3)										//Virtual coordinate

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
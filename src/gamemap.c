#include "setup.h"

Panel mapBorder = {
	LEVEL_X_OFFSET - 1, LEVEL_Y_OFFSET - 1,
	LEVEL_WIDTH + 2, LEVEL_HEIGHT + 2,
};

Level * newLevel(){
	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	atexit_add(newLevel);

	newLevel->tiles = saveTilePositions();

	newLevel->player = newPlayer(3, 3, "@");

	return newLevel;
}

void freeLevel(Level * level){
	int x, y;

	for (y = 0; y < LEVEL_HEIGHT; y++){
		for (x = 0; x < LEVEL_WIDTH; x++){
			freeTile(level->tiles[y][x]);
		}
		free(level->tiles[y]);
	}

	free(level->tiles);
	free(level);
}

Tile *** saveTilePositions(){
	int x, y;
	Tile *** tiles;

	tiles = malloc(sizeof(Tile **) * LEVEL_HEIGHT);
	atexit_add(tiles);

	for (y = 0; y < LEVEL_HEIGHT; y++){
		tiles[y] = malloc(sizeof(Tile *) * LEVEL_WIDTH);
		atexit_add(tiles[y]);
		for (x = 0; x < LEVEL_WIDTH; x++){
			tiles[y][x] = newTile();
		}
	}
	return tiles;
}

void drawLevel(Level * level, App* app) {
	int x, y;

	for (y = 0; y < LEVEL_HEIGHT; y++){
		for (x = 0; x < LEVEL_WIDTH; x++){
			if ((x == level->player->x) && (y == level->player->y))
				drawPlayer(level->player, app);
			else
				gridUTF8(level->tiles[y][x]->graphic, x, y, app);
		}
	}
}
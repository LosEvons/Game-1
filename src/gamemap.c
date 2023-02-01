#include "setup.h"

extern const SDL_Color COLOR_GREY;
extern const SDL_Color COLOR_WHITE;

extern const Position prevPos;

Panel mapBorder = {
	LEVEL_X_OFFSET - 1, LEVEL_Y_OFFSET - 1,
	LEVEL_WIDTH + 2, LEVEL_HEIGHT + 2,
};

Level * newLevel(){
	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	atexit_add(newLevel);

	newLevel->tiles = initFloorTiles();

	newLevel->player = newPlayer(3, 3, "@", newLevel);

	return newLevel;
}

Level * newCellarLevel(){
	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	atexit_add(newLevel);

	newLevel->tiles = initWallTiles();

	newLevel->rooms = generateRooms();

	carveRooms(newLevel);

	carveHallways(newLevel);

	Position playerStartPos = getRoomCenter(newLevel->rooms[0]);
	newLevel->player = newPlayer(playerStartPos.x, playerStartPos.y, "@", newLevel);

	return newLevel;
}

Level * newCavernLevel(){
	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	atexit_add(newLevel);

	newLevel->tiles = initWallTiles();

	newLevel->rooms = NULL;

	releaseHulks(newLevel);

	Position playerStartPos = prevPos;
	newLevel->player = newPlayer(playerStartPos.x, playerStartPos.y, "@", newLevel);

	return newLevel;
}

Tile *** initFloorTiles(){
	int x, y;
	Tile *** tiles;

	tiles = malloc(sizeof(Tile **) * LEVEL_HEIGHT);
	atexit_add(tiles);

	for (y = 0; y < LEVEL_HEIGHT; y++){
		tiles[y] = malloc(sizeof(Tile *) * LEVEL_WIDTH);
		atexit_add(tiles[y]);
		for (x = 0; x < LEVEL_WIDTH; x++){
			tiles[y][x] = newTile(".", COLOR_GREY, 0);
		}
	}
	return tiles;
}

Tile *** initWallTiles(){
	int x, y;
	Tile *** tiles;

	tiles = malloc(sizeof(Tile **) * LEVEL_HEIGHT);
	atexit_add(tiles);

	for (y = 0; y < LEVEL_HEIGHT; y++){
		tiles[y] = malloc(sizeof(Tile *) * LEVEL_WIDTH);
		atexit_add(tiles[y]);
		for (x = 0; x < LEVEL_WIDTH; x++){
			tiles[y][x] = newTile("#", COLOR_WHITE, 1);
		}
	}
	return tiles;
}

void drawLevel(Level * level, App* app) {
	int x, y;

	for (y = 0; y < LEVEL_HEIGHT; y++){
		for (x = 0; x < LEVEL_WIDTH; x++){
			if (
				(x >= (level->player->position->x - PLAYER_FOV)) &&
				(x <= (level->player->position->x + PLAYER_FOV)) &&
				(y >= (level->player->position->y - PLAYER_FOV)) &&
				(y <= (level->player->position->y + PLAYER_FOV))
				){
				if (level->tiles[y][x]->explored == 0){
					level->tiles[y][x]->explored = 1;
				}
				if ((x == level->player->position->x) && (y == level->player->position->y))
					drawPlayer(level->player, app);
				else
					gridUTF8(level->tiles[y][x]->graphic, x, y, app);
			}
			else if (level->tiles[y][x]->explored == 1){
				gridUTF8(level->tiles[y][x]->graphicExplored, x, y, app);
			}	
		}
	}
}

void freeLevel(Level * level){
	int x, y;

	for (y = 0; y < LEVEL_HEIGHT; y++){
		for (x = 0; x < LEVEL_WIDTH; x++){
			freeTile(level->tiles[y][x]);
			level->tiles[y][x] = NULL;
		}
		free(level->tiles[y]);
		level->tiles[y] = NULL;
	}

	free(level->tiles);
	level->tiles = NULL;
	free(level);
	level = NULL;
}
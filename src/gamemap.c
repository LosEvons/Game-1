#include "setup.h"

Graphic * newGraphic(){
	Graphic * newGraphic;
	newGraphic = malloc(sizeof(Graphic));

	newGraphic->glyph = malloc(sizeof("."));
	newGraphic->glyph = ".";

	return newGraphic;
}

Level * newLevel(){
	Level * newLevel;
	newLevel = malloc(sizeof(Level));

	newLevel->tiles = saveTilePositions();

	newLevel->player = newPlayer(3 * TILE_WIDTH, 3 * TILE_HEIGHT, "@");

	return newLevel;
}

Tile * newTile(){
	Tile * newTile;
	newTile = malloc(sizeof(Tile));
	newTile->graphic = malloc(sizeof(Graphic *));
	newTile->graphic = newGraphic();

	return newTile;
}

Tile *** saveTilePositions(){
	int x, y;
	Tile *** tiles;

	tiles = malloc(sizeof(Tile *) * LEVEL_HEIGHT);

	for (y = 0; y < LEVEL_HEIGHT; y++){
		tiles[y] = malloc(sizeof(Tile *) * LEVEL_WIDTH);
		for (x = 0; x < LEVEL_WIDTH; x++){
			tiles[y][x] = newTile();
		}
	}

	return tiles;
}

void freeLevel(Level * level){
	int x, y;
	for (y = 0; y < LEVEL_HEIGHT; y++){
		for (x = 0; x < LEVEL_WIDTH; x++){
			free(level->tiles[y][x]);
		}
		free(level->tiles[y]);
	}

	free(level);
}

void drawLevel(Level * level, App* app) {
	int x, y;
	for (y = TILE_HEIGHT; y < LEVEL_HEIGHT; y += TILE_HEIGHT){
		for (x = TILE_WIDTH; x < LEVEL_WIDTH; x += TILE_WIDTH){
			if ((x == level->player->x) && (y == level->player->y))
				{ drawPlayer(level->player, app); }
			else 
				{ drawUTF8(level->tiles[y][x]->graphic->glyph, x, y, app); }
		}
	}
}
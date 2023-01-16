#include "setup.h"

Graphic * newGraphic(char * nglyph){
	Graphic * newGraphic;
	newGraphic = malloc(sizeof(Graphic));
	atexit_add(newGraphic);

	newGraphic->glyph = malloc(sizeof(nglyph));
	atexit_add(newGraphic->glyph);
	newGraphic->glyph = nglyph;

	return newGraphic;
}

void freeGraphic(Graphic * graphic) {
	free(graphic->glyph);
	free(graphic);
}

Level * newLevel(){
	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	atexit_add(newLevel);

	newLevel->tiles = saveTilePositions();

	newLevel->player = newPlayer(3 * TILE_WIDTH, 3 * TILE_HEIGHT, "@");

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

Tile * newTile(){
	Tile * newTile;
	newTile = malloc(sizeof(Tile));
	atexit_add(newTile);
	newTile->graphic = malloc(sizeof(Graphic *));
	newTile->graphic = newGraphic(".");

	return newTile;
}

void freeTile(Tile * tile){
	freeGraphic(tile->graphic);
	free(tile);
}

Tile *** saveTilePositions(){
	int x, y;
	Tile *** tiles;

	tiles = malloc(sizeof(Tile *) * LEVEL_HEIGHT);
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
	for (y = TILE_HEIGHT; y < LEVEL_HEIGHT; y += TILE_HEIGHT){
		for (x = TILE_WIDTH; x < LEVEL_WIDTH; x += TILE_WIDTH){
			if ((x == level->player->x) && (y == level->player->y))
				{ drawPlayer(level->player, app); }
			else 
				{ drawUTF8(level->tiles[y][x]->graphic->glyph, x, y, app); }
		}
	}
}
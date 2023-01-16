#include "setup.h"

extern const SDL_Color COLOR_WHITE;
extern const SDL_Color COLOR_GREY;

Tile * newTile(){
	Tile * newTile;
	newTile = malloc(sizeof(Tile));
	atexit_add(newTile);

	newTile->graphic = malloc(sizeof(Graphic *));
	atexit_add(newTile->graphic);

	newTile->graphic = newGraphic(".", COLOR_GREY);

	return newTile;
}

void freeTile(Tile * tile){
	freeGraphic(tile->graphic);
	free(tile);
}
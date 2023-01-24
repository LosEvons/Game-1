#include "setup.h"

extern const SDL_Color COLOR_WHITE;
extern const SDL_Color COLOR_GREY;



Tile * newTile(char* glyph, SDL_Color color, int blocking){
	Tile * newTile;
	newTile = malloc(sizeof(Tile));
	atexit_add(newTile);

	newTile->graphic = newGraphic(glyph, color);

	newTile->blocking = blocking;

	return newTile;
}

void freeTile(Tile * tile){
	free(tile);
}
#include "setup.h"

TTF_Font* loadTileset() {
	TTF_Font* tileset = TTF_OpenFont(GAME_FONT, 24);

	if (tileset == NULL) {
		TTF_SetError("Loading failed (code: %d)", 142);
		printf("Error: %s\n", SDL_GetError());
		exit(1);
	}
	printf("Succesfully loaded tileset!\n");

	return tileset;
}

void unloadTileset(TTF_Font* tileset) { TTF_CloseFont(tileset); }
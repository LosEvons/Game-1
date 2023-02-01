#include "setup.h"

// Colors
const SDL_Color COLOR_WHITE = {255, 255, 255, 255};
const SDL_Color COLOR_GREY = {150, 150, 150, 255};
const SDL_Color COLOR_RED = {200, 0, 0, 255};
const SDL_Color COLOR_DARK_GREY = {75, 75, 75, 255};

Graphic newGraphic(char *nglyph, SDL_Color color){
	Graphic newGraphic = {
		nglyph,
		color,
	};

	return newGraphic;
}

void freeGraphic(Graphic * graphic) {
	free(graphic->glyph);
	free(graphic);
}

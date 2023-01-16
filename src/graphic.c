#include "setup.h"

// Colors
const SDL_Color COLOR_WHITE = {255, 255, 255};
const SDL_Color COLOR_GREY = {150, 150, 150};
const SDL_Color COLOR_RED = {200, 0, 0};

Graphic * newGraphic(char * nglyph, SDL_Color color){
	Graphic * newGraphic;
	newGraphic = malloc(sizeof(Graphic));
	atexit_add(newGraphic);

	newGraphic->glyph = malloc(sizeof(nglyph));
	atexit_add(newGraphic->glyph);
	newGraphic->glyph = nglyph;

	newGraphic->fg = color;

	return newGraphic;
}

void freeGraphic(Graphic * graphic) {
	free(graphic->glyph);
	free(graphic);
}

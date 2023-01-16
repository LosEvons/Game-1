#include "setup.h"

void prepareScene(App* app){
	SDL_SetRenderDrawColor(app->renderer, 50, 50, 50, 255);
	SDL_RenderClear(app->renderer);
}

int presentScene(App* app, Level * level){
	//drawScreenEdges(app);
	drawLeftPanel(app);
	drawLevel(level, app);
	SDL_RenderPresent(app->renderer);

	return 1;
}

void drawUTF8(char *drawable, int x, int y, App* app) {
	SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Solid(app->tileset, drawable, color);
	SDL_Rect rect = { x, y, TILE_WIDTH, TILE_HEIGHT, };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}
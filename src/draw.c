#include "setup.h"

void prepareScene(App* app){
	SDL_SetRenderDrawColor(app->renderer, 50, 50, 50, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App* app){
	drawPlayer(app->player, app);
	SDL_RenderPresent(app->renderer);
}

void drawGlyph(int drawable, int x, int y, App* app){
	SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderGlyph_Solid(app->tileset, drawable, color);
	SDL_Rect rect = { x, y, sur->w, sur->h, };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}
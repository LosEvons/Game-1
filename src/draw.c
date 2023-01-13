#include "setup.h"

void prepareScene(App* app){
	SDL_SetRenderDrawColor(app->renderer, 50, 50, 50, 255);
	SDL_RenderClear(app->renderer);
}

int presentScene(App* app, Level * level){
	drawPlayer(app->player, app);
	drawScreenEdges(app);
	drawLevel(level, app);
	SDL_RenderPresent(app->renderer);

	return 1;
}

void drawGlyph(int drawable, int x, int y, App* app){
	SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderGlyph_Solid(app->tileset, drawable, color);
	SDL_Rect rect = { x, y, sur->w, sur->h, };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}

void drawUTF8(char *drawable, int x, int y, App* app) {
	SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Solid(app->tileset, drawable, color);
	//SDL_Rect rect = { x, y, sur->w, sur->h, };
	SDL_Rect rect = { x, y, TILE_WIDTH, TILE_HEIGHT, };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}

void drawScreenEdges(App* app){
	int x, y;

	// Corners
	drawUTF8(WALL_TOP_LEFT, 0, 0, app); // Left top
	drawUTF8(WALL_BOTTOM_LEFT, 0, SCREEN_HEIGHT - TILE_HEIGHT, app); // Left bottom
	drawUTF8(WALL_TOP_RIGHT, SCREEN_WIDTH - TILE_WIDTH, 0, app); // Right top
	drawUTF8(WALL_BOTTOM_RIGHT, SCREEN_WIDTH - TILE_WIDTH, SCREEN_HEIGHT - TILE_HEIGHT, app); // Right bottom
	
	for (x = TILE_WIDTH; x < SCREEN_WIDTH - TILE_WIDTH; x += TILE_WIDTH){
		drawUTF8(WALL_HORIZONTAL, x, 0, app);
		drawUTF8(WALL_HORIZONTAL, x, SCREEN_HEIGHT - TILE_HEIGHT, app);
	}

	for (y = TILE_HEIGHT; y < SCREEN_HEIGHT - TILE_HEIGHT; y += TILE_HEIGHT){
		drawUTF8(WALL_VERTICAL, 0, y, app);
		drawUTF8(WALL_VERTICAL, SCREEN_WIDTH - TILE_WIDTH, y, app);
	}
}
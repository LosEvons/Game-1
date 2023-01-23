#include "setup.h"

extern Panel logPanel;
extern Panel leftPanel;
extern Panel rightPanel;
extern Panel mapBorder;

void prepareScene(App* app){
	SDL_SetRenderDrawColor(app->renderer, 50, 50, 50, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App* app, Level * level){
	drawPanel(app, logPanel);
	drawMessages(app);
	drawPanel(app, leftPanel);
	drawPanel(app, rightPanel);
	drawPanel(app, mapBorder);
	drawLevel(level, app);
	SDL_RenderPresent(app->renderer);

	gameState = PLAYER_TURN;
}

void drawUTF8Log(Message * message, int x, int y, int adjustedIndex, App* app) {
	int truex = (x * TILE_WIDTH);
	int truey = (y * TILE_HEIGHT) - LOG_TILE_HEIGHT - (adjustedIndex * LOG_TILE_PADDING);

	int strW = strlen(message->text) * LOG_TILE_WIDTH;

	int r, g, b, a;

	switch(message->level){
		case MUTED:
			r = 255; g = 255; b = 255; a = 100;
			break;
		case ERROR:
			r = 255; g = 0; b = 0; a = 255;
			break;
		case SYSTEM_MESSAGE:
			r = 0; g = 255; b = 0; a = 255;
			break;
		case DATA:
			r = 200; g = 200; b = 255; a = 255;
			break;

		default:
			r = 255; g = 255; b = 255; a = 255;
			break;
	}
	
	SDL_Color color = {r, g, b, a};

	SDL_Surface *sur = TTF_RenderUTF8_Blended(app->tileset, message->text, color);
	SDL_Rect rect = { truex, truey, strW, LOG_TILE_HEIGHT };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}

void drawUTF8(char *drawable, int x, int y, App* app) {
	int truex = (x * TILE_WIDTH);
	int truey = (y * TILE_HEIGHT);

	SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Solid(app->tileset, drawable, color);
	SDL_Rect rect = { truex, truey, TILE_WIDTH, TILE_HEIGHT };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}

void gridUTF8(Graphic *drawable, int x, int y, App* app) {
	int truexoffs = LEVEL_X_OFFSET * TILE_WIDTH;	// Get size of offset in pixels (not coordinates)
	int trueyoffs = LEVEL_Y_OFFSET * TILE_HEIGHT;	// ^^
	int truex = (x * TILE_WIDTH) + truexoffs;		// Get actual anchor position in pixels (not coordinates)
	int truey = (y * TILE_HEIGHT) + trueyoffs;		// ^^

	//SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Blended(app->tileset, drawable->glyph, drawable->fg);
	SDL_Rect rect = { truex, truey, TILE_WIDTH, TILE_HEIGHT };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}

void freeDrawUTF8(char *drawable, int x, int y, App* app){
	SDL_Color color = {255, 255, 255, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Solid(app->tileset, drawable, color);
	SDL_Rect rect = { x, y, TILE_WIDTH, TILE_HEIGHT };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, sur);
	SDL_FreeSurface(sur);

	SDL_RenderCopy(app->renderer, tex, NULL, &rect);
}
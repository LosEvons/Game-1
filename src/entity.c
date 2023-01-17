#include "setup.h"

extern const SDL_Color COLOR_RED;

Player * newPlayer(int x, int y, char* glyph, Level * level){
	Player * player = malloc(sizeof(Player));
	atexit_add(player);
	player->x = x;
	player->y = y;

	player->graphic = malloc(sizeof(Graphic));
	atexit_add(player->graphic);
	player->graphic = newGraphic(glyph, COLOR_RED);

	player->level = malloc(sizeof(Level *));
	atexit_add(player->level);
	player->level = level;

	return player;
}

void movePlayerTo(Player * player, int newx, int newy){
	player->x = newx;
	player->y = newy;
}

void movePlayerFrom(Player * player, int dx, int dy){
	int newx = player->x + dx;
	int newy = player->y + dy;

	int tileCountY = sizeof(player->level->tiles[0]);
	int tileCountX = sizeof(player->level->tiles[0]);
	printf("Y: %d X: %d", tileCountY, tileCountX);

	if ((newx >= 0) && (newx < LEVEL_WIDTH)){
		player->x += (player->level->tiles[newy][newx]->blocking == 0) ? dx : 0;
	}

	if ((newy >= 0) && (newy < LEVEL_HEIGHT)){
		player->y += (player->level->tiles[newy][newx]->blocking == 0) ? dy : 0;
	}
}

void drawPlayer(Player * player, App* app){	gridUTF8(player->graphic, player->x, player->y, app); }
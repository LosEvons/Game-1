#include "setup.h"

extern const SDL_Color COLOR_RED;

Player * newPlayer(int x, int y, char* glyph, Level * level){
	Player * player = malloc(sizeof(Player));
	atexit_add(player);
	
	player->position = malloc(sizeof(Position));
	atexit_add(player->position);
	player->position->x = x;
	player->position->y = y;

	player->graphic = newGraphic(glyph, COLOR_RED);

	player->level = malloc(sizeof(Level));
	atexit_add(player->level);
	player->level = level;

	return player;
}

void movePlayerTo(Player * player, int newx, int newy){
	player->position->x = newx;
	player->position->y = newy;
}

void movePlayerFrom(Player * player, int dx, int dy){
	int newx = player->position->x + dx;
	int newy = player->position->y + dy;

	if ((newx < 0) || (newx >= LEVEL_WIDTH) || (newy < 0) || (newy >= LEVEL_HEIGHT)){
		return;
	}
	else {
		player->position->x += (player->level->tiles[newy][newx]->blocking == 0) ? dx : 0;
		player->position->y += (player->level->tiles[newy][newx]->blocking == 0) ? dy : 0;

		gameState = PROCESSING;
	}
}

void drawPlayer(Player * player, App* app){
	gridUTF8(player->graphic, player->position->x, player->position->y, app);
}
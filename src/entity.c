#include "setup.h"

Player * newPlayer(int x, int y, int glyph){
	Player * player = malloc(sizeof(Player));
	player->x = x;
	player->y = y;
	player->glyph = glyph;

	return player;
}

void movePlayerTo(Player * player, int newx, int newy){
	player->x = newx;
	player->y = newy;
}

void movePlayerFrom(Player * player, int dx, int dy){
	int newx = player->x + dx;
	int newy = player->y + dy;
	if ((newx > 0) && (newx < SCREEN_WIDTH - TILE_SIZE) && (newy > 0) && (newy < SCREEN_HEIGHT - TILE_SIZE)) {
		player->y += dy;
		player->x += dx;
	}
}

void drawPlayer(Player * player, App* app){
	drawGlyph(player->glyph, player->x, player->y, app);
}
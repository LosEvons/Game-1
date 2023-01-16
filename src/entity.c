#include "setup.h"

Player * newPlayer(int x, int y, char* glyph){
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

	player->x += ((newx < (LEVEL_WIDTH)) && (newx > 0)) ? dx : 0;
	player->y += ((newy < (LEVEL_HEIGHT)) && (newy > 0)) ? dy : 0;
}

void drawPlayer(Player * player, App* app){	drawUTF8(player->glyph, player->x, player->y, app); }
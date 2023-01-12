#include "setup.h"

Player * newPlayer(int x, int y, int glyph){
	Player * player = malloc(sizeof(Player*));
	player->x = x;
	player->y = y;
	player->glyph = glyph;

	return player;
}

void movePlayerTo(Player * player, int newx, int newy){
	player->x = newx;
	player->y = newy;
}

int movePlayerFrom(Player * player, int dx, int dy){
	int newx = player->x + dx;
	int newy = player->y + dy;
	if ((newx < 0) || (newx > SCREEN_WIDTH) || (newy < 0) || (newy > SCREEN_HEIGHT)) {
		printf("Moving our of bounds!\n");
		return 0;
	}
	player->x += dx;
	player->y += dy;

	return 0;
}

void drawPlayer(Player * player, App* app){
	drawGlyph(player->glyph, player->x, player->y, app);
}
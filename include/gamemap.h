#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "setup.h"

typedef struct Tile {
	Graphic * graphic;
	int blocking;
} Tile;

typedef struct Room {
	int x;
	int y;
	int w;
	int h;
} Room;

typedef struct Level {
	Tile *** tiles;
	Player * player;
	Room ** rooms;
} Level;

#endif
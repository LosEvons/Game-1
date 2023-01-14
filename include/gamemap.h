#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "setup.h"

typedef struct Graphic {
	char * glyph;
} Graphic;

typedef struct Tile {
	Graphic * graphic;
} Tile;

typedef struct Level {
	Tile *** tiles;
	Player * player;
} Level;

#endif
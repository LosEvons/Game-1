#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "setup.h"

typedef struct Tile {
	char* glyph;
} Tile;

typedef struct Level {
	Tile *** tiles;
} Level;

#endif
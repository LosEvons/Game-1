#ifndef ENTITY_H
#define ENTITY_H
#include "setup.h"

typedef struct Player {
	int x;
	int y;
	Graphic * graphic;
	struct Level * level;
} Player;

#endif
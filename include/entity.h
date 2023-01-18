#ifndef ENTITY_H
#define ENTITY_H
#include "setup.h"

typedef struct Player {
	struct Position * position;
	struct Graphic * graphic;
	struct Level * level;
} Player;

#endif
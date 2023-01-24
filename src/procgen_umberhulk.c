#include "setup.h"

extern const SDL_Color COLOR_GREY;

const unsigned int umberhulkAge = 15;
const unsigned int umberhulkPopulation = 25;

void releaseHulks(Level * level){
	int i;
	for (i = 0; i < umberhulkPopulation; i++){
		castUmberhulk(level);
	}
}

void castUmberhulk(Level * level){
	int i;

	int startx = rand() % (LEVEL_WIDTH - 2) + 1;
	int starty = rand() % (LEVEL_HEIGHT - 2) + 1;

	Position currentPosition = { startx, starty };

	for (i = 0; i < umberhulkAge; i++){
		level->tiles[currentPosition.y][currentPosition.x] = newTile(".", COLOR_GREY, 0);
		moveHulk(&currentPosition);
	}
}

void moveHulk(Position * currentPosition){
	int dx = rand() % 3 - 1;
	int dy = rand() % 3 - 1;
	int newx = currentPosition->x + dx;
	int newy = currentPosition->y + dy;

	if ((newx < 0) || (newx >= LEVEL_WIDTH) || (newy < 0) || (newy >= LEVEL_HEIGHT)){
		return;
	}
	else {
		currentPosition->x = newx;
		currentPosition->y = newy;
	}
}

#include "setup.h"

extern const SDL_Color COLOR_GREY;

const unsigned int umberhulkAge = 150;
const unsigned int umberhulkPopulation = 10;

Position prevPos = { -1, -1 };

void releaseHulks(Level * level){
	unsigned int i;
	for (i = 0; i < umberhulkPopulation; i++){
		castUmberhulk(level);
	}
}

void castUmberhulk(Level * level){
	unsigned int i;
	Position currentPosition = {-1, -1 };

	if (prevPos.x < 0 || prevPos.y < 0){
		int startx = rand() % (LEVEL_WIDTH - 2) + 1;
		int starty = rand() % (LEVEL_HEIGHT - 2) + 1;
		currentPosition.x = startx;
		currentPosition.y = starty;
	}
	else{
		currentPosition = prevPos;
	}
	

	for (i = 0; i < umberhulkAge; i++){
		level->tiles[currentPosition.y][currentPosition.x] = newTile(".", COLOR_GREY, 0);
		moveHulk(&currentPosition);
	}

	prevPos = currentPosition;

}

void moveHulk(Position * currentPosition){
	int dm = rand() % 3 - 1; // Movement amount
	int dd = rand() % 2; // Direction
	int newx, newy;

	if (dd < 1){ // Move on X axis
		newx = currentPosition->x + dm;
		newy = currentPosition->y;
	}
	else{ // Move on Y axis
		newx = currentPosition->x;
		newy = currentPosition->y + dm;
	}

	if ((newx < 0) || (newx >= LEVEL_WIDTH) || (newy < 0) || (newy >= LEVEL_HEIGHT)){
		return;
	}
	else {
		currentPosition->x = newx;
		currentPosition->y = newy;
	}
}

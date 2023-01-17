#include "setup.h"

extern const SDL_Color COLOR_GREY;

Room * newRoom(int x, int y, int w, int h){
	Room * newRoom;
	newRoom = malloc(sizeof(Room));
	atexit_add(newRoom);
	newRoom->x = x;
	newRoom->y = y;
	newRoom->w = w;
	newRoom->h = h;

	return newRoom;
}

void carveRoom(Level * level, Room * room){
	int x, y;
	for (x = room->x; x < room->x + room->w; x++){
		for (y = room->y; y < room->y + room->h; y++){
			level->tiles[x][y] = newTile(".", COLOR_GREY, 0);
		}
	}
}
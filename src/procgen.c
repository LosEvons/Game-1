#include "setup.h"

extern const SDL_Color COLOR_GREY;

int randRange(int min, int max){ return rand() % ((max) - (min) + 1) + (min); }

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

Room * generateRoom(){
	int randx, randy, randw, randh;

	randw = rand() % MAX_ROOM_SIZE + MIN_ROOM_SIZE;
	randh = rand() % MAX_ROOM_SIZE + MIN_ROOM_SIZE;

	randx = rand() % (LEVEL_WIDTH - randw);
	randy = rand() % (LEVEL_HEIGHT - randh);

	printf("%d %d %d %d\n", randw, randh, randx, randy);
	printf("%d %d\n", LEVEL_WIDTH, LEVEL_HEIGHT);

	Room * aRoom = newRoom(randx, randy, randw, randh);

	return aRoom;
}

void carveRoom(Level * level, Room * room){
	int x, y;
	for (x = room->x; x < room->x + room->w; x++){
		for (y = room->y; y < room->y + room->h; y++){
			level->tiles[y][x] = newTile(".", COLOR_GREY, 0);
		}
	}
}

void carveRooms(Level * level){
	int i;
	for (i = 0; i < MAX_ROOMS; i++){
		carveRoom(level, level->rooms[i]);
	}
}

Room ** generateRooms(){
	int i;
	Room ** rooms = malloc(sizeof(Room *) * MAX_ROOMS);
	atexit_add(rooms);

	for (i = 0; i < MAX_ROOMS; i++){
		rooms[i] = generateRoom();
	}

	return rooms;
}
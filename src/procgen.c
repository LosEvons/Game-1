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

Position getRoomCenter(Room * room){
	Position centerPos;
	centerPos.x = room->x + (room->w / 2);
	centerPos.y = room->y + (room->h / 2);

	return centerPos;
}

int detectRoomOverlap(Room ** rooms, Room * room, int currentRoomCount){
	int i;

	/*	If room1->x2 is LARGER than room2->x
		AND room1->x is SMALLER than room2->x2
		AND
		If room->y2 is LARGER than room2->y
		and room1->y is SMALLER than room2->y2
	*/

	for (i = 0; i < currentRoomCount; i++){
		if (
				(
					((room->x + room->w) >= rooms[i]->x)
					&& (room->x <= (rooms[i]->x + rooms[i]->w))
				) 
				&&
				(
					((room->y + room->h) >= rooms[i]->y)
					&& (room->y <= (rooms[i]->y + rooms[i]->h))
				)
			){
			printf("Room rejected!\n");
			return 1;
		}
	}
	
	return 0;
}

Room * generateRoom(){
	int randx, randy, randw, randh;

	randw = rand() % MAX_ROOM_SIZE + MIN_ROOM_SIZE;
	randh = rand() % MAX_ROOM_SIZE + MIN_ROOM_SIZE;

	randx = rand() % (LEVEL_WIDTH - 2 - randw) + 1;
	randy = rand() % (LEVEL_HEIGHT - 2 - randh) + 1;

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

Room ** generateRooms(Level * level){
	int i;
	Room ** rooms = malloc(sizeof(Room) * MAX_ROOMS);
	atexit_add(rooms);

	for (i = 0; i < MAX_ROOMS; i++){
		Room * gendRoom = generateRoom();

		if (i == 0){
			rooms[i] = gendRoom;
			continue;
		}

		int overlapped = detectRoomOverlap(rooms, gendRoom, i);
		if (overlapped == 1){
			i--;
			continue;
		}

		else
			rooms[i] = gendRoom;
	}

	return rooms;
}

void carveHorizontalHallway(Level * level, int startX, int endX, int baseY){
	int x;

	if ((endX - startX) > 0){
		for (x = startX; x < endX; x++){
			level->tiles[baseY][x] = newTile(".", COLOR_GREY, 0);
		}
		return;
	}
	else if ((endX - startX) < 0){
		for (x = startX; x > endX; x--){
			level->tiles[baseY][x] = newTile(".", COLOR_GREY, 0);
		}
		return;
	}
	else
		return;
}

void carveVerticalHallway(Level * level, int startY, int endY, int baseX){
	int y;

	if ((endY - startY) > 0){
		for (y = startY; y < endY; y++){
			level->tiles[y][baseX] = newTile(".", COLOR_GREY, 0);
		}
		return;
	}
	else if ((endY - startY) < 0){
		for (y = startY; y > endY; y--){
			level->tiles[y][baseX] = newTile(".", COLOR_GREY, 0);
		}
		return;
	}
	else
		return;
}

void carveHallways(Level * level){
	int i;

	for (i = 0; i < MAX_ROOMS; i++){
		if (i == 0)
			continue;

		Position startPos = getRoomCenter(level->rooms[i]);
		Position endPos = getRoomCenter(level->rooms[i - 1]);

		int dieroll = rand() % 2;

		if (dieroll == 1){
			carveHorizontalHallway(level, startPos.x, endPos.x, startPos.y);
			carveVerticalHallway(level, startPos.y, endPos.y, endPos.x);
		}
		else {
			carveVerticalHallway(level, startPos.y, endPos.y, startPos.x);
			carveHorizontalHallway(level, startPos.x, endPos.x, endPos.y);
		}

	}
}
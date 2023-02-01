#ifndef __STRUCTS_H__
#define __STRUCTS_H__
// SDL IMPORT HAS TO COME BEFORE THIS
// OTHERWISE SDL MODULES HAVE NO DEFINITIONS INSIDE HERE
// Probably fixable in some way

/* GameState */
enum GameState {
	PLAYER_TURN, PROCESSING,
};

/* App */
typedef struct App {
	SDL_Window* window;
 	SDL_Renderer* renderer;
	TTF_Font* tileset;
} App;

/* Position */ // Possibly it's own file in the future
typedef struct Position {
	int x;
	int y;
} Position;

/* graphic.h */
typedef struct Graphic {
	char * glyph;
	SDL_Color fg;
} Graphic;

/* player.h */
typedef struct Player {
	struct Position * position;
	struct Graphic graphic;
	struct Level * level;
} Player;

/* gamemap.h */
typedef struct Tile {
	struct Graphic graphic;
	int blocking;
} Tile;

typedef struct Room {
	int x;
	int y;
	int w;
	int h;
} Room;

typedef struct Level {
	struct Tile *** tiles;
	struct Player * player;
	struct Room ** rooms;
} Level;

/* logger.h */
enum MessageLevel {
	MUTED = 0, ERROR = 1, SYSTEM_MESSAGE = 2, DATA = 3
};

typedef struct Message{
	char text[51];
	enum MessageLevel level;
	int key;
	struct Message * next;
} Message;

typedef struct MessageLog {
	enum MessageLevel treshold;
	struct Message *head;
} MessageLog;

/* ui.h */
typedef struct Panel {
	int x;
	int y;
	int w;
	int h;
} Panel;

#endif
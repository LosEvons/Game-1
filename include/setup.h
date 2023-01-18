#ifndef SETUP_H
#define SETUP_H

// Standard libraries
#include <stdio.h>
#include <time.h>
// SDL libraries
#include "SDL.h"
#include "SDL_ttf.h"
// Own header files
#include "definitions.h"
// Logger
#include "logger.h"
// Graphic
#include "graphic.h"
// Entities
#include "entity.h"
// Map
#include "gamemap.h"
// UI
#include "ui.h"

/* Structs */
typedef struct App {
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* tileset;
} App;

typedef struct Position {
	int x;
	int y;
} Position;

/* memory_utils.c */
void atexit_add(void *data);
void clean(void);

/* logger.c */
MessageLog * initMessageLog();
void addMessage(MessageLog * messageLog, enum MessageLevel messageLevel, char* messageText);
Message * getMessageFromIndex(MessageLog * messageLog, int index);
Message * scrollBackMessageLog(Message * message);
Message * scrollForwardMessageLog(Message * message);
void drawMessages(MessageLog * messageLog, App * app);

/* initializeSDL.c */
App * initSDL(); // Initializes base SDL functions (SDL_Init, TTF_Init). Used at the start of a program.
int uninitSDLBase(App * app); // Uninitializes base SDL functions (SDL_Init, TTF_Init). Used at the end of a program.

#define GAME_FONT "./resources/MorePerfectDosVGA.ttf" // Font/Tileset used (ttf format)
TTF_Font* loadTileset(); // My own extension to SDL:s own tileset load function (added error handling).
void unloadTileset(); // Unloads the font/tileset. Used at the end of a program.

/* handleInput.c */
int doInput(Player * player);

/* draw.c */
void prepareScene(App* app);
int presentScene(App* app, Level * level);
void drawGlyph(int drawable, int x, int y, App* app);
void drawUTF8(char* drawable, int x, int y, App* app);
void drawUTF8Text(Message * message, int x, int y, App* app);
void gridUTF8(Graphic * drawable, int x, int y, App* app);
void freeDrawUTF8(char* drawable, int x, int y, App* app);

/* ui.c */
void drawBox(App * app, int x, int y, int w, int h);
void drawPanel(App * app, Panel panel);

/* entity.c */
Player * newPlayer(int x, int y, char* glyph, Level * level);
void movePlayerTo(Player* player, int newx, int newy);
void movePlayerFrom(Player* player, int dx, int dy);
void drawPlayer(Player* player, App* app);

/* graphic.c */
Graphic * newGraphic(char * nglyph, SDL_Color color);
void freeGraphic(Graphic * graphic);

/* tile.c */
Tile * newTile(char* glyph, SDL_Color color, int blocking);
void freeTile(Tile * tile);

/* gamemap.c */
Level * newLevel();
Level * newCellarLevel();
void freeLevel(Level * level);
Tile *** initFloorTiles();
Tile *** initWallTiles();
void drawLevel(Level * level, App * app);

/* procgen.c */
Room * newRoom(int x, int y, int w, int h);
Position getRoomCenter(Room * room);
Room * generateRoom();
void carveRoom(Level * level, Room * room);
void carveRooms(Level * level);
Room ** generateRooms();

void carveHallways(Level * level);
void carveVerticalHallway(Level * level, int startY, int endY, int baseX);
void carveHorizontalHallway(Level * level, int startX, int endX, int baseY);

#endif
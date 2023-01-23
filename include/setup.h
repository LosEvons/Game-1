#ifndef SETUP_H
#define SETUP_H

// Standard libraries
#include <stdio.h>
#include <stdbool.h>
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
void atexit_add(void *data); // Add item to list that is cleaned at the end of the program
void clean(void); // Clean (free) all items in list

/* logger.c */
void insertFirst(MessageLog * messageLog, int key, char data[], enum MessageLevel level); // Add message to index
void addLog(MessageLog * messageLog, char data[], enum MessageLevel level); // Add message to end of list
bool isEmpty(MessageLog * messageLog); // Checks if message log is empty
int getLogLength(MessageLog * messageLog); // Get number of messages in message log
Message * find(MessageLog * messaegLog, int key); // Find message by index
void drawMessages(MessageLog * messageLog, App * app); // Draw messages in log screen


/* initializeSDL.c */
App * initSDL(); // Initializes base SDL functions (SDL_Init, TTF_Init). Used at the start of a program.
int uninitSDLBase(App * app); // Uninitializes base SDL functions (SDL_Init, TTF_Init). Used at the end of a program.

#define GAME_FONT "./resources/MorePerfectDosVGA.ttf" // Font/Tileset used (ttf format)
TTF_Font* loadTileset(); // My own extension to SDL:s own tileset load function (added error handling).
void unloadTileset(); // Unloads the font/tileset. Used at the end of a program.

/* handleInput.c */
int doInput(Player * player); // Handle player input (currently always, in the future will be divided by game states)

/* draw.c */
void prepareScene(App* app); // Operations done before scene rendering (slightly odd function, but occasionally useful)
int presentScene(App* app, Level * level, MessageLog * messageLog); // Render all elements of scene (no specific order as of 19/1/23)
void drawGlyph(int drawable, int x, int y, App* app); // Old function used to draw single byte ASCII characters
void drawUTF8(char* drawable, int x, int y, App* app); // Function to draw character on screen using our virtual coordinate grid
void drawUTF8Log(Message * message, int x, int y, int adjustedIndex, App* app); // A variant drawing function used to draw log messages
void gridUTF8(Graphic * drawable, int x, int y, App* app); // A variant drawing function used to draw map tiles
void freeDrawUTF8(char* drawable, int x, int y, App* app); // A variant drawing function independent of the virtual coordinate grid

/* ui.c */
void drawBox(App * app, int x, int y, int w, int h); // Draws a box shape
void drawPanel(App * app, Panel panel); // Draws a box shape provided by panel struct (Panels don't have much functionality as of 19/1/23)

/* entity.c */
Player * newPlayer(int x, int y, char* glyph, Level * level); // Initialize a new player character (there should only be one player at a time)
void movePlayerTo(Player* player, int newx, int newy); // Moves player to a set of absolute coordinates (no safeguards)
void movePlayerFrom(Player* player, int dx, int dy); // Moves player in relation to it's current position (safeguards)
void drawPlayer(Player* player, App* app); // Draw player on screen

/* graphic.c */
Graphic * newGraphic(char * nglyph, SDL_Color color); // Create a new graphic used in drawing
void freeGraphic(Graphic * graphic); // A function to free a graphic mid program (by default taken care of by memory_utils.c:clean

/* tile.c */
Tile * newTile(char* glyph, SDL_Color color, int blocking); // Create a new tile struct
void freeTile(Tile * tile); // A function to free a tile mid program (by default taken care of by memory_utils.c:clean

/* gamemap.c */
Level * newLevel(); // Create a new level/map filled with floor tiles (possibly non-functional as of 19/1/23) 
Level * newCellarLevel(); // Create a new level/map filled with wall tiles
void freeLevel(Level * level); // A function to free a level mid program (by default taken care of by memory_utils.c:clean
Tile *** initFloorTiles(); // Fills level->tiles with floor tiles
Tile *** initWallTiles(); // Fills level->tiles with wall tiles
void drawLevel(Level * level, App * app); // Draws all tiles and player using draw.c:gridUTF8

/* procgen.c */
Room * newRoom(int x, int y, int w, int h); // Generate a new rectangular room 
Position getRoomCenter(Room * room); // Returns room center coordinates as a Position struct
Room * generateRoom(); // Generates a random room using parameters defined in definitions.h (MAX_ROOMS, MAX_ROOM_WIDTH, etc...)
void carveRoom(Level * level, Room * room); // Changes all tiles within a rooms' coordinates to floor tiles
void carveRooms(Level * level); // Repeats carveRoom for each room in Level
Room ** generateRooms(); // Repeats generateRoom until room count is equal to definitions.h:MAX_ROOMS

void carveHallways(Level * level); // Carves a L-shaped hallway between the centers of two rooms (repeats for each room in Level->rooms)
void carveVerticalHallway(Level * level, int startY, int endY, int baseX); // Changes all tiles in vertical portion of hallway to floor tiles
void carveHorizontalHallway(Level * level, int startX, int endX, int baseY); // Changes all tiles in horizontal portion of hallway to floor tiles

#endif

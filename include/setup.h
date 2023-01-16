#ifndef SETUP_H
#define SETUP_H

// Standard libraries
#include "stdio.h"
// SDL libraries
#include "SDL.h"
#include "SDL_ttf.h"
// Own header files
#include "definitions.h"
// Entities
#include "entity.h"
// Map
#include "gamemap.h"

/* memory_utils.c */
void atexit_add(void *data);
void clean(void);

/* initializeSDL.c */
typedef struct App {
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* tileset;
} App;

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

/* ui.c */
void drawScreenEdges(App * app);
void drawLeftPanel(App * app);

/* entity.c */
Player * newPlayer(int x, int y, char* glyph);
void movePlayerTo(Player* player, int newx, int newy);
void movePlayerFrom(Player* player, int dx, int dy);
void drawPlayer(Player* player, App* app);

/* gamemap.c */
Graphic * newGraphic(char * nglyph);
void freeGraphic(Graphic * graphic);
Level * newLevel();
void freeLevel(Level * level);
Tile * newTile();
void freeTile(Tile * tile);
Tile *** saveTilePositions();
void drawLevel(Level * level, App * app);

#endif
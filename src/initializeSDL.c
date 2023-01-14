#include "setup.h"

App * initSDL() {
	// Flag variables
	int rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags  = 0;

	// Initialize base systems (SDL & TTF)
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		exit(1);
	}
	printf("SDL succesfully initialized!\n");	

	if (TTF_Init() < 0) {
		printf("Error initializing TTF: %s\n", SDL_GetError());
		exit(1);
	}
	printf("TTF succesfully initialized!\n");

	// Initialize window
	SDL_Window *window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!window){
		printf("Failed to open %d x %d window: %s\n", 
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	// Initialize renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	if (!renderer){
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	// Initialize tileset
	TTF_Font* tileset = TTF_OpenFont(GAME_FONT, TILE_SIZE);

	if(!tileset){
		TTF_SetError("Loading failed (code: %d)", 142);
		printf("Error: %s\n", SDL_GetError());
		exit(1);
	}
	printf("Succesfully loaded tileset!\n");

	// Initialize App
	App * app = malloc(sizeof(App));
	app->window = window;
	app->renderer = renderer;
	app->tileset = tileset;
	//app->player = newPlayer(48, 240, "@");
	printf("Succesfully initialized App!\n");

	return app;
}

int uninitSDLBase(App * app) {
	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->renderer);
	TTF_CloseFont(app->tileset);
	free(app);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
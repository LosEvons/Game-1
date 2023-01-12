#include "setup.h"

int initSDLBase() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return -1;
	}
	printf("SDL succesfully initialized!\n");	

	if (TTF_Init() < 0) {
		printf("Error initializing TTF: %s\n", SDL_GetError());
		return -1;
	}
	printf("TTF succesfully initialized!\n");

	return 0;
}

int uninitSDLBase() {
	TTF_Quit();
	SDL_Quit();

	return 0;
}
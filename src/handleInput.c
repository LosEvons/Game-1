#include "setup.h"

void doInput(Player * player){
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch(event.type){

		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
			case SDLK_UP:
				printf("Test\n");
				movePlayerFrom(player, 0, -2);
				break;
			case SDLK_DOWN:
				movePlayerFrom(player, 0, 2);
				break;
			case SDLK_LEFT:
				movePlayerFrom(player, -2, 0);
				break;
			case SDLK_RIGHT:
				movePlayerFrom(player, 2, 0);
				break;
			default:
				break;
			}

		default:
			break;
		}
	}
}
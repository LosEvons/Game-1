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
				movePlayerFrom(player, 0, -24);
				break;
			case SDLK_DOWN:
				movePlayerFrom(player, 0, 24);
				break;
			case SDLK_LEFT:
				movePlayerFrom(player, -24, 0);
				break;
			case SDLK_RIGHT:
				movePlayerFrom(player, 24, 0);
				break;
			default:
				break;
			}

		default:
			break;
		}
	}
}
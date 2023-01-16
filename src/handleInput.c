#include "setup.h"

int doInput(Player * player){
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch(event.type){

		case SDL_QUIT:
			exit(0);	
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
			case SDLK_UP:
				movePlayerFrom(player, 0, -TILE_HEIGHT);
				return 1;
				break;
			case SDLK_DOWN:
				movePlayerFrom(player, 0, TILE_HEIGHT);
				return 1;
				break;
			case SDLK_LEFT:
				movePlayerFrom(player, -TILE_WIDTH, 0);
				return 1;
				break;
			case SDLK_RIGHT:
				movePlayerFrom(player, TILE_WIDTH, 0);
				return 1;
				break;

			case SDLK_q:
				exit(0);
				break;

			default:
				return 0;
				break;
			}

		default:
			return 0;
			break;
		}
	}

	return 0;
}
#include "setup.h"

extern enum GameState gameState;
extern enum LevelType levelType;

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
				movePlayerFrom(player, 0, -1);
				break;
			case SDLK_DOWN:
				movePlayerFrom(player, 0, 1);
				break;
			case SDLK_LEFT:
				movePlayerFrom(player, -1, 0);
				break;
			case SDLK_RIGHT:
				movePlayerFrom(player, 1, 0);
				break;

			case SDLK_q:
				exit(0);
				break;

			default:
				break;
			}

		default:
			break;
		}
	}
}

enum LevelType doMenuInput(){
	SDL_Event event;

	while(SDL_PollEvent(&event)){
		switch(event.type){
		case SDL_QUIT:
			exit(0);
			break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
			case SDLK_1:
				gameState = PROCESSING;
				return DEFAULT_LEVEL;
				break;
			case SDLK_2:
				gameState = PROCESSING;
				return CELLAR_LEVEL;
				break;
			case SDLK_3:
				gameState = PROCESSING;
				return CAVE_LEVEL;
				break;

			case SDLK_q:
				exit(0);
				break;

			default:
				break;
			}
		default:
			break;
		}
	}

	return NO_LEVEL;
}
#include "setup.h"

enum GameState gameState = MAIN_MENU;
enum LevelType levelType = NO_LEVEL;

int main(int argc, char* argv[]) {

	atexit( clean );
	srand(time(NULL));	// Random seed from time

	messageLog.head = NULL;
	messageLog.treshold = SYSTEM_MESSAGE;

	addLog("Logger initialized.", SYSTEM_MESSAGE);

	Level * level = NULL;

	App * app = initSDL();

	while (1)
	{
		switch (gameState){
			case MAIN_MENU:
				levelType = doMenuInput();
				presentMenuScene(app);
				break;
			case PLAYER_TURN:
				doInput(level->player);
				break;
			case PROCESSING:
				prepareScene(app);
				presentScene(app, level);
				break;

			default:
				break;
		}

		if (level == NULL && levelType != NO_LEVEL){
			switch (levelType){
			case DEFAULT_LEVEL:
				level = newLevel();
				break;
			case CELLAR_LEVEL:
				level = newCellarLevel();
				break;
			case CAVE_LEVEL:
				level = newCavernLevel();
				break;

			default:
				break;
			}
		}

		SDL_Delay(16);
	}


	return 0;
}
#include "setup.h"

enum GameState gameState = PROCESSING;

int main(int argc, char* argv[]) {

	atexit( clean );

	srand(time(NULL));	// Random seed from time

	App * app = initSDL();
	//Level * level = newCellarLevel();
	Level * level = newCavernLevel();

	messageLog.head = NULL;
	messageLog.treshold = SYSTEM_MESSAGE;

	addLog("Logger initialized.", SYSTEM_MESSAGE);

	int running = 1;

	while (running)
	{
		switch (gameState){
			case PLAYER_TURN:
				doInput(level->player);
				break;
			case PROCESSING:
				prepareScene(app);
				presentScene(app, level);

			default:
				break;
		}

		SDL_Delay(16);
	}


	return 0;
}
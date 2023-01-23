#include "setup.h"

extern MessageLog messageLog;

int main(int argc, char* argv[]) {

	atexit( clean );

	srand(time(NULL));	// Random seed from time

	App * app = initSDL();
	Level * level = newCellarLevel();

	messageLog.head = NULL;
	messageLog.current = NULL;
	messageLog.treshold = SYSTEM_MESSAGE;

	addLog("Logger initialized.", SYSTEM_MESSAGE);

	int running = 1;
	int drawn = 0;

	while (running)
	{
		prepareScene(app);

		if (doInput(level->player)) { drawn = 0; }

		if (!drawn) { drawn = presentScene(app, level); }

		SDL_Delay(16);
	}


	return 0;
}
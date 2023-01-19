#include "setup.h"

int main(int argc, char* argv[]) {

	atexit( clean );

	srand(time(NULL));	// Random seed from time

	MessageLog * messageLog = malloc(sizeof(MessageLog));
	atexit_add(messageLog);	

	App * app = initSDL();
	Level * level = newCellarLevel();

	messageLog->head = NULL;
	messageLog->current = NULL;
	messageLog->treshold = SYSTEM_MESSAGE;

	addLog(messageLog, "Logger initialized.", SYSTEM_MESSAGE);

	int running = 1;
	int drawn = 0;

	while (running)
	{
		prepareScene(app);

		if (doInput(level->player)) { drawn = 0; }

		if (!drawn) { drawn = presentScene(app, level, messageLog); }

		SDL_Delay(16);
	}


	return 0;
}
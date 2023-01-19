#include "setup.h"

int main(int argc, char* argv[]) {

	atexit( clean );

	srand(time(NULL));	// Random seed from time

	App * app = initSDL();
	Level * level = newCellarLevel();

	MessageLog * messageLog = malloc(sizeof(MessageLog));
	atexit_add(messageLog);

	messageLog->head = NULL;
	messageLog->current = NULL;
	messageLog->treshold = DATA;

	insertFirst(messageLog, 1, "test1");
	insertFirst(messageLog, 2, "TEST2");
	insertFirst(messageLog, 3, "test3");
	insertFirst(messageLog, 4, "TEST4");

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
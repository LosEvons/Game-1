#include "setup.h"

MessageLog * messageLog;

int main(int argc, char* argv[]) {

	atexit( clean );

	srand(time(NULL));	// Random seed from time

	App * app = initSDL();
	Level * level = newCellarLevel();

	messageLog = initMessageLog();
	addMessage(messageLog, DATA, "Test 1");
	addMessage(messageLog, DATA, "TEST 2");
	//addMessage(messageLog, DATA, "Test 3");
	//addMessage(messageLog, DATA, "TEST 4");

	//addMessage(&messageLog, DATA, "Test Message!\n");

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
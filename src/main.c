#include "setup.h"

int main(int argc, char* argv[]) {

	atexit( clean );

	srand(time(NULL));	// Random seed from time

	App * app = initSDL();
	Level * level = newCellarLevel();

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
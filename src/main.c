#include "setup.h"

const SDL_Color COLOR_WHITE = {255, 255, 255};
const SDL_Color COLOR_GREY = {150, 150, 150};
const SDL_Color COLOR_RED = {200, 0, 0};

int main(int argc, char* argv[]) {

	atexit( clean );

	App * app = initSDL();
	Level * level = newLevel();

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
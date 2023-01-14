#include "setup.h"

int main(int argc, char* argv[]) {

	App * app = initSDL();
	Level * level = newLevel();

	_onexit( uninitSDLBase );

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
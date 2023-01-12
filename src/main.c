#include "setup.h"

int main(int argc, char* argv[]) {

	App * app = initSDL();

	_onexit( uninitSDLBase );

	int running = 1;

	while (running)
	{
		prepareScene(app);

		doInput(app->player);

		presentScene(app);

		SDL_Delay(16);
	}

	return 0;
}
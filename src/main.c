#include "setup.h"

int main(int argc, char* argv[]) {

	App * app = initSDL();
	Player * player = newPlayer(50, 100, '@');

	_onexit( uninitSDLBase );

	int running = 1;

	while (running)
	{
		prepareScene(app);

		doInput(player);

		presentScene(app, player);

		SDL_Delay(16);
	}
	
	// Cleanup
	if (uninitSDLBase() == 0) {
		return 0;
	}

	return 0;
}
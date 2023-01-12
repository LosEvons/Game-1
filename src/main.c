#include "setup.h"

int main(int argc, char* argv[]) {
	if (initSDLBase() < 0) {
		return 0;
	}

	if (uninitSDLBase() == 0) {
		return 0;
	}

	return 0;
}
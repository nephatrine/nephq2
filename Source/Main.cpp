#include "GameEngine.h"
#include <SDL_main.h>

int main( int argc, char *argv[] )
{	Game::Engine game( argc, argv );
	return game.run();
}

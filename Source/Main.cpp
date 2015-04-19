// -----------------------------------------------
// Include Headers
//

#include "GameEngine.h"
#include <SDL_main.h>

// -----------------------------------------------
// main
// SDL Entry Point
//

int main(int argc, char *argv[])
{
	Game::Engine game(argc, argv);
	return game.run();
}

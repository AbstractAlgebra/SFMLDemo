#include "Game.hpp"

void main(int argc, char** argv[])
{

	Game game;
	game.getWindow();
	while (!game.getWindow()->isDone())
	{
		//Game loop
		game.handleInput();
		game.update();
		game.render();
		game.restartClock();
	}

}
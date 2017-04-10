#include "Game.hpp"

void main(int argc, char** argv[])
{

	Game game;
	while (true)
	{
		game.update();
		game.render();
	}

}
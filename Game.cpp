#include "Game.h"

#include <iostream>
#include <SDL2/SDL.h>

void Game::run()
{
	if (systemState == PLAY)
	{
		handleInput();

		updateLogic();

		render();
	}
}

void Game::handleInput()
{
	if(_input->getPressed(SDL_SCANCODE_P))
	{
		if(systemState != PAUSE) systemState = PAUSE;
		else systemState = PLAY;
	}

	_level->handleInput();
}
void Game::updateLogic()
{
	_level->updateLogic();
}

void Game::render()
{
	_level->render();
}

SystemState Game::getState()
{
	return systemState;
}

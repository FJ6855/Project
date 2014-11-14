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
	// TODO: check for game paused, call level->handleInput
	if(_input->getPressed(SDL_SCANCODE_P))
	{
		if(systemState != PAUSE) systemState = PAUSE;
		else systemState = PLAY;

		if (systemState == PLAY) std::cout << "State is now PLAY" << endl;
		if (systemState == PAUSE) std::cout << "State is now PAUSE" << endl;
	}
}
void Game::updateLogic()
{
	// TODO: call level->updateLogic()
}

void Game::render()
{
	// TODO: call level->render()
}

SystemState Game::getState()
{
	return systemState;
}

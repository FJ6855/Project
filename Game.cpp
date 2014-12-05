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
    else if (systemState == PAUSE)
    {
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

    if(_level->getPlayerState() == PlayerState::dead) 
    {
	if(_highScore->compare(_level->getPlayer()->getScore()))
	{
	    systemState = WRITENAMEMENU;
	    _highScore->setCurrentScore(_level->getPlayer()->getScore());
	}

	_level->reset();

    }

    _level->handleCollision();
}

void Game::render()
{
    _level->render(_renderer);
}

SystemState Game::getState()
{
    return systemState;
}

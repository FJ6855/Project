#include <SDL2/SDL.h>

#include "Game.h"

void Game::run()
{
    if (systemState == START_GAME)
    {
	_level->reset();

	systemState = PLAY;
    }
    
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
    if (_input->getPressed(SDL_SCANCODE_P))
    {
	if (systemState != PAUSE) 
	    systemState = PAUSE;
	else 
	    systemState = PLAY;
    }

    _level->handleInput();
}

void Game::updateLogic()
{
    _level->updateLogic();
    
    Player* player = _level->getPlayer();
    
    if (player->getState() == PlayerState::dead) 
    {
	if (player->getSaveHighScore() && _highScore->compare(player->getScore()))
	{
	    systemState = WRITENAMEMENU;
	    _highScore->setCurrentScore(player->getScore());
	}
	else 
	{
	    systemState = START_GAME;
	}
    }
}

void Game::render()
{
    _level->render(_renderer);
}

SystemState Game::getState()
{
    return systemState;
}

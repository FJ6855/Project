#include "PlayerRenderer.h"
#include <string>
#include <iostream>

PlayerRenderer::~PlayerRenderer()
{

}

void PlayerRenderer::loadContent()
{
	_playerTextureRunningRight1 = _rm->loadTexture("playerTextureRunningRight1");
	_playerTextureRunningRight2 = _rm->loadTexture("playerTextureRunningRight2");
	_playerTextureRunningRight3 = _rm->loadTexture("playerTextureRunningRight3");

	_playerTextureRunningLeft1 = _rm->loadTexture("playerTextureRunningLeft1");
	_playerTextureRunningLeft2 = _rm->loadTexture("playerTextureRunningLeft2");
	_playerTextureRunningLeft3 = _rm->loadTexture("playerTextureRunningLeft3");
	_playerTextureInAirRight = _rm->loadTexture("playerTextureJumpingRight");
	_playerTextureInAirLeft = _rm->loadTexture("playerTextureJumpingLeft");

	_healthBarTextTexture = _rm->loadTexture("Health: ", SDL_Color{ 255, 255, 255 });
	_healthBarTexture = _rm->loadTexture(1, 16, 255, 0, 0);

	_scoreTextTexture = _rm->loadTexture("Score: ", SDL_Color{ 255, 255, 255 });
	_lastScoreTextTexture = _rm->loadTexture("Last score: ", SDL_Color{ 255, 255, 255 });
}

void PlayerRenderer::render(Player* player, SDL_Renderer* renderer)
{
	//Render player
	if (_playerFrame >= 20) _playerFrame = 0;

	if (player->getState() == inAir || player->getState() == jumping)
	{
		if (player->getDirection() == left)
			_playerTexture = _playerTextureInAirLeft;
		else if (player->getDirection() == right)
			_playerTexture = _playerTextureInAirRight;
	}
	else if (player->getXvel() == 0)
	{
		if (player->getDirection() == right)
			_playerTexture = _playerTextureRunningRight1;
		else if (player->getDirection() == left)
			_playerTexture = _playerTextureRunningLeft1;
	}
	else if (player->getState() == running)
	{
		_playerFrame++;

		if (player->getDirection() == left)
		{
			if (_playerFrame >= 0 && _playerFrame < 5)
				_playerTexture = _playerTextureRunningLeft1;
			else if ((_playerFrame >= 6 && _playerFrame < 10) || (_playerFrame >= 16 && _playerFrame < 20))
				_playerTexture = _playerTextureRunningLeft2;
			else if (_playerFrame >= 11 && _playerFrame < 15)
				_playerTexture = _playerTextureRunningLeft3;
		}
		else if (player->getDirection() == right)
		{
		  if (_playerFrame >= 0 && _playerFrame < 5)
		    _playerTexture = _playerTextureRunningRight1;
		  else if ((_playerFrame >= 6 && _playerFrame < 10) || (_playerFrame >= 16 && _playerFrame < 20))
		    _playerTexture = _playerTextureRunningRight2;
		  else if (_playerFrame >= 11 && _playerFrame < 15)
		    _playerTexture = _playerTextureRunningRight3;
		}
	}

	_playerTexture->render(renderer, 448 - (player->getWidth() / 2), player->getY(), player->getWidth(), player->getHeight());

	//Render health bar
	_healthBarTextTexture->render(renderer, 350, 25, _healthBarTextTexture->getWidth(), _healthBarTextTexture->getHeight());

	if (player->getHealth() > 0)
	{
		_healthBarTexture->render(renderer, 420, 25, player->getHealth(), 16);
	}

	//Render score
	delete _scoreTexture; //free the old texture
	_scoreTexture = _rm->loadTexture(std::to_string(player->getScore()), SDL_Color{0, 255, 0});
       
	_scoreTextTexture->render(renderer, 350, 45, _scoreTextTexture->getWidth(),  _scoreTextTexture->getHeight());
	_scoreTexture->render(renderer, 420, 45, _scoreTexture->getWidth(), _scoreTexture->getHeight());

	delete _lastScoreTexture; //free the old texture
	_lastScoreTexture = _rm->loadTexture(std::to_string(player->getHighscore()), SDL_Color{ 0, 255, 0 });

	_lastScoreTextTexture->render(renderer, 298, 65, _lastScoreTextTexture->getWidth(), _lastScoreTextTexture->getHeight());
	_lastScoreTexture->render(renderer, 420, 65, _lastScoreTexture->getWidth(), _lastScoreTexture->getHeight());
}


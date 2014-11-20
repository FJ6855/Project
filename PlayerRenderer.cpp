#include "PlayerRenderer.h"


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
}

void PlayerRenderer::render(Player* player, SDL_Renderer* renderer)
{
	if (_playerFrame >= 40) _playerFrame = 0;


	if (player->getXvel() == 0)
	{
		if (player->getDirection() == left)
			_playerTexture = _playerTextureRunningLeft1;
		else if (player->getDirection() == right)
			_playerTexture = _playerTextureRunningRight1;
	}
	else if (player->getState() == running)
	{
		_playerFrame++;

		if (player->getDirection() == left)
		{
			if (_playerFrame >= 0 && _playerFrame < 10)
				_playerTexture = _playerTextureRunningLeft1;
			else if ((_playerFrame >= 11 && _playerFrame < 20) || (_playerFrame >= 31 && _playerFrame < 40))
				_playerTexture = _playerTextureRunningLeft2;
			else if (_playerFrame >= 21 && _playerFrame < 30)
				_playerTexture = _playerTextureRunningLeft3;
		}
		else if (player->getDirection() == right)
		{
			if (_playerFrame < 20)
				_playerTexture = _playerTextureRunningRight1;
			else if (_playerFrame < 40)
				_playerTexture = _playerTextureRunningRight2;
			else
				_playerTexture = _playerTextureRunningRight3;
		}
	}
	else if (player->getState() == inAir)
	{
		if (player->getDirection() == left)
			_playerTexture = _playerTextureInAirLeft;
		else if (player->getDirection() == right)
			_playerTexture = _playerTextureInAirRight;
	}

	_playerTexture->render(renderer, 448 - (player->getWidth() / 2), player->getY(), player->getWidth(), player->getHeight());
}


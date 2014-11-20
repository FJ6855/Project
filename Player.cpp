#include "Player.h"

#include <iostream>
  void Player::handleInput(InputHandler* input)
  {
	  _xVel = 0;

	  //Move right and left
	  if (input->getKey(SDL_SCANCODE_D) || input->getKey(SDL_SCANCODE_RIGHT))
	    _xVel = _speed;
	  else if ((input->getKey(SDL_SCANCODE_A) || input->getKey(SDL_SCANCODE_LEFT)) && _x - 10 > -896)
	    _xVel = -_speed;
	      
	  if ((input->getKey(SDL_SCANCODE_W) || input->getKey(SDL_SCANCODE_SPACE)) && _playerState == running)
	    {
	      _yVel = -10;
	    }
  }

  void Player::updateLogic()
  {
	  if (_xVel < 0) _playerDirection = left;
	  else if (_xVel > 0) _playerDirection = right;

      _yVel += 0.4;
	  _x += _xVel;
	  _y += _yVel;

	  if (_y > 600) 
	    _playerState = dead;

  }

  float Player::getXvel()
  {
	  return _xVel;
  }

  float Player::getYvel()
  {
	  return _yVel;
  }

  int Player::getSpeed()
  {
	  return _speed;
  }

  void Player::setXvel(int xVel)
  {
	  _xVel = xVel;
  }

  void Player::setYvel(int yVel)
  {
	  _yVel = yVel;
  }

void Player::setState(PlayerState state)
{
  _playerState = state;
}

PlayerState Player::getState()
{
  return _playerState;
}

PlayerDirection Player::getDirection()
{
	return _playerDirection;
}

void Player::setState(PlayerDirection direction)
{
	_playerDirection = direction;
}

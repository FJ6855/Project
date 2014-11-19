#include "Player.h"

#include <iostream>
  void Player::handleInput(InputHandler* input)
  {
	  _xVel = 0;

	  //Move right and left
	  if (input->getKey(SDL_SCANCODE_D))
		  _xVel = _speed;
	  else if (input->getKey(SDL_SCANCODE_A) && _x - 10 > -896)
		  _xVel = -_speed;

	  if (input->getPressed(SDL_SCANCODE_W))
		  _yVel = -8;

  }

  void Player::updateLogic()
  {
	  _x += _xVel;
	  _y += _yVel;

	  _yVel += 0.4;
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



#include "Player.h"

#include <iostream>
  void Player::handleInput(InputHandler* input)
  {
	  _xVel = 0;

	  //Move right and left
	  if (input->getKey(SDL_SCANCODE_D) || input->getKey(SDL_SCANCODE_RIGHT))
	    _xVel = _speed;
	  else if ((input->getKey(SDL_SCANCODE_A) || input->getKey(SDL_SCANCODE_LEFT)) && _x > -1328)
	    _xVel = -_speed;
	      
	  if ((input->getKey(SDL_SCANCODE_W) || input->getKey(SDL_SCANCODE_SPACE) || input->getKey(SDL_SCANCODE_UP)) && _playerState == running)
	    {
	      _yVel = -8.5;
		  _playerState = jumping;
		  _jumpBoost = true;
		  _jumpBoostGravity = _gravity;
	    }

	  if (_playerState == jumping && !(input->getKey(SDL_SCANCODE_UP) || input->getKey(SDL_SCANCODE_W) || input->getKey(SDL_SCANCODE_SPACE)))
	  {
		  _jumpBoost = false;
	  }

	  if (input->getPressed(SDL_SCANCODE_G))
	    {
	      _godMode = !_godMode;
	      
	      std::cout << "God mode: " << _godMode << std::endl;
	    }
  }

  void Player::updateLogic()
  {

	  //std::cout << _jumpBoost << std::endl;
	  //Update direction
	  if (_xVel < 0) _playerDirection = left;
	  else if (_xVel > 0)_playerDirection = right;

	  //Update score
	  if (_xVel > 0 && _playerDirection == PlayerDirection::right)
	  {
		  _scoreOffset += _xVel;

		  if (_scoreOffset > 0) 
		  {
			  _scoreOffset = 0;
			  _score += _xVel;
		  }
	  }
	  else if (_xVel < 0 && _playerDirection == PlayerDirection::left)
	  {
		  _scoreOffset += _xVel;
	  }
	  
	  if(_score < 0) _score = 0;

	  //Gravity
	  if (_playerState == jumping && _jumpBoost)
	  {
		  if (_jumpBoostGravity > 0.15)
		    _jumpBoostGravity -= 0.01f;
		  else
		    _jumpBoost = false;

		  _yVel += _jumpBoostGravity;
	  }
	  else
		  _yVel += _gravity;

	  //Move player
	  _x += _xVel;
	  _y += _yVel;
	  
	  //Lose life by time
	  if (_godMode == false)
		  _health -= _healthLossFactor;//_currentDifficulty * _healthLossFactor;

	  //Check if player is dead
	  if (_y > 600 || _health <= 0)
	    {
	      if (_godMode == false)
		_playerState = dead;
	      else
		_y = 0;
	    }
  }

  float Player::getXvel()
  {
	  return _xVel;
  }

  float Player::getYvel()
  {
	  return _yVel;
  }

  float Player::getSpeed()
  {
	  return _speed;
  }

void Player::setSpeed(float speed)
{
  _speed = speed;
}

void Player::resetSpeed()
{
  _speed = _defaultSpeed;
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

void Player::setDirection(PlayerDirection direction)
{
	_playerDirection = direction;
}

float Player::getHealth()
{
  return _health;
}
void Player::setHealth(int health)
{
  _health = health;
}

int Player::getScore()
{
  return _score;
}

void Player::setScore(int score)
{
  _score = score;
}

void Player::setDifficulty(int difficulty)
{
	_currentDifficulty = difficulty;
}

void Player::setHighscore(int highscore)
{
	_highscore = highscore;
}

int Player::getHighscore()
{
	return _highscore;
}

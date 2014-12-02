#include "Player.h"

#include <iostream>

void Player::reset()
{
  _x = -896;
  _y = 200;
  _speed = 8;
  _defaultSpeed = _speed;
  _gravity = 0.45f;
  _xVel = 0;
  _yVel = 0;
  _playerState = inAir;
  _playerDirection = right;
  _health = 100;
  _powerUpTimer = 0;

  if(_highscore < _score)
    _highscore = _score;

  _lastScore = _score;
  _score = 0;
  _scoreOffset = 0;
  _healthLossFactor = 0.05f;
  _jumpBoost = true;
  _jumpBoostGravity = _gravity;
  _movementDifference = 0;   
  _godMode = false;
  _lastX = _x;
}

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

  _powerUpTimer -= 1;

  if (_powerUpTimer <= 0)
    {
      _powerUpTimer = 0;
      
      resetSpeed();
    }
}

void Player::updateLogic()
{ 
  //Update direction
  if (_xVel < 0) _playerDirection = left;
  else if (_xVel > 0)_playerDirection = right;
  
  if(_x - _lastX < -500)
    _movementDifference = _x - _lastX + 896;
  else
    _movementDifference = _x - _lastX;

  _lastX = _x;

  _scoreOffset += _movementDifference;
  
  //Update score
  if (_scoreOffset > 0 && _movementDifference > 0) 
    {
      _scoreOffset = 0;

      _score += _movementDifference;
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
    {
      _yVel += _gravity;
    }
	  

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

int Player::getMovementDifference()
{
  return _movementDifference;
}

void Player::setMovementDifference(int movementDifference)
{
  _movementDifference = movementDifference;
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

  if (_health > 100)
    _health = 100;
}

int Player::getPowerUpTimer()
{
  return _powerUpTimer;
}

void Player::setPowerUpTimer(int timer)
{
  _powerUpTimer = timer;
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

void Player::setLastScore(int lastScore)
{
	_lastScore = lastScore;
}

int Player::getLastScore()
{
	return _lastScore;
}

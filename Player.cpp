#include "Player.h"

#include <iostream>

Player* Player::clone() const
{
    return new Player(*this);
}

void Player::reset()
{
    _x = -896;
    _y = 200;
    
    resetSpeed();

    _gravity = 0.45f;
    _xVel = 0;
    _yVel = 0;
    _playerState = inAir;
    _playerDirection = right;
    _health = 100;
    _currentDifficulty = 1;

    if (_highscore < _score && _saveHighScore)
	_highscore = _score;
    
    if (_saveHighScore)
	_lastScore = _score;

    _score = 0;
    _scoreOffset = 0;
    _healthLossFactor = 0.05f;
    _jumpBoost = true;
    _jumpBoostGravity = _gravity;

    _canDoubleJump = false;
    _canGlideJump = false;

    _lastX = _x;
    _movementDifference = 0;  
 
    _godMode = false;
    _saveHighScore = true;

    _powerUps.clear();
}

void Player::handleInput(InputHandler* input)
{
    _xVel = 0;
    
    //Move right and left
    if (input->getKey(SDL_SCANCODE_D) || input->getKey(SDL_SCANCODE_RIGHT))
    {
	_xVel = _speed + _airSpeed;
    }
    else if ((input->getKey(SDL_SCANCODE_A) || input->getKey(SDL_SCANCODE_LEFT)) && _x > -1328)
	_xVel = -_speed + _airSpeed;
    else
	_xVel = _airSpeed;
     
    if ((input->getKey(SDL_SCANCODE_W) || input->getKey(SDL_SCANCODE_SPACE) || input->getKey(SDL_SCANCODE_UP)) && (_playerState == PlayerState::standing || _playerState == PlayerState::running))
    {
	jump();
    }
    else if ((input->getKey(SDL_SCANCODE_W) || input->getKey(SDL_SCANCODE_SPACE) || input->getKey(SDL_SCANCODE_UP)) && _canDoubleJump && _playerState == PlayerState::inAir)
    {
	jump();

	_canDoubleJump = false;
    }

    if (_playerState == PlayerState::jumping && !(input->getKey(SDL_SCANCODE_UP) || input->getKey(SDL_SCANCODE_W) || input->getKey(SDL_SCANCODE_SPACE)))
    {
	_jumpBoost = false;
    }

    if (input->getPressed(SDL_SCANCODE_G))
    {
	_godMode = !_godMode;
	     
	_saveHighScore = false;

	std::cout << "God mode: " << _godMode << std::endl;
    }

    if((!input->getKey(SDL_SCANCODE_D) && !input->getKey(SDL_SCANCODE_RIGHT)) || (!input->getKey(SDL_SCANCODE_A) && !input->getKey(SDL_SCANCODE_LEFT)))
    {
	_airSpeed = 0;
    }
}

void Player::updateLogic()
{ 
    _lastPlayerState = _playerState;

    //Update direction
    if (_xVel < 0) 
	_playerDirection = left;
    else if (_xVel > 0)
	_playerDirection = right;
  
    if(_x - _lastX < -500)
	_movementDifference = _x - _lastX + 896;
    else
	_movementDifference = _x - _lastX;

    _lastX = _x;
  
    //Update score
    _scoreOffset += _movementDifference;

    if (_scoreOffset > 0 && _movementDifference > 0) 
    {
	_scoreOffset = 0;

	_score += _movementDifference;
    }

    //Gravity
    if (_playerState == PlayerState::jumping && _jumpBoost)
    {
	if (_jumpBoostGravity > 0.15f)
	    _jumpBoostGravity -= 0.01f;
	else
	{
	    if (_canGlideJump)
	    {
		_jumpBoostGravity = 0;
		_yVel = 0;
	    }
	    else
	    {
		_jumpBoost = false;
	    }
	}

	_yVel += _jumpBoostGravity;
    }
    else
    {
	_playerState = PlayerState::inAir;
      
	if (_yVel < 20)
	    _yVel += _gravity;
    }
	  
    //Move player
    _x += _xVel;
    _y += _yVel;
	  
    //Lose life by time
    if (_godMode == false)
	_health -= _healthLossFactor;
    
    //Check if player is dead
    if (_y > 600 || _health <= 0)
    {
	if (_godMode == false)
	    _playerState = PlayerState::dead;
	else
	    _y = 0;
    }
}

void Player::updatePowerUps()
{
    for (PowerUp* p : _powerUps)
    {
	p->updateLogic(this);
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
    
    _airSpeed = 0;
}

void Player::setAirSpeed(float airSpeed)
{
    _airSpeed = airSpeed;
}

bool Player::getCanDoubleJump()
{
    return _canDoubleJump;
}

void Player::setCanDoubleJump(bool canDoubleJump)
{
    _canDoubleJump = canDoubleJump;
}

bool Player::getCanGlideJump()
{
    return _canGlideJump;
}

void Player::setCanGlideJump(bool canGlideJump)
{
    _canGlideJump = canGlideJump;
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

void Player::setLastState(PlayerState state)
{
    _lastPlayerState = state;
}

PlayerState Player::getLastState()
{
    return _lastPlayerState;
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

std::vector<PowerUp*> Player::getPowerUps()
{
    return _powerUps;
}

void Player::addPowerUp(PowerUp* powerUp)
{
    bool updated = false;

    for (PowerUp* p : _powerUps)
    {
	if (p->getType() == powerUp->getType())
	{	    
	    p->setTimer(powerUp->getTimer());
	    
	    updated = true;

	    break;
	}
    }

    if (updated == false)
	_powerUps.push_back(powerUp);
}

int Player::getScore()
{
    return _score;
}

void Player::setScore(int score)
{
    _score = score;
}

int Player::getDifficulty()
{
    return _currentDifficulty;
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

void Player::jump()
{
    _yVel = -8.5;

    _playerState = PlayerState::jumping;

    _jumpBoost = true;

    _jumpBoostGravity = _gravity;
}

bool Player::isGod()
{
    return _godMode;
}

bool Player::getSaveHighScore()
{
    return _saveHighScore;
}

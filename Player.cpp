#include "Player.h"

  void Player::damage(float dmg)
  {
    _health-=dmg;
    //if(_health<=0)
      //_state = dead;
  }

  void Player::affectSpeed(float speedFactor)
  {
    if(_state == standing)
      {
	//do nothing
      }
    else if(_state == running)
      {
	if(_xVelocity < 0)
	  {
	    _xVelocity += speedFactor;
	  }
	else if(_xVelocity > 0)
	  {
	    _xVelocity -= speedFactor;
	  }
      }
    else if(_state == jumping)
      {
      
      }
  }

  bool Player::isDead()//kan sättas ihop med den under med "dead" state?
  {
    return _state==dead;
  }
  
  playerState Player::getState()
  {
    return _state;
  }

  int Player::getScore()
  {
    return _score;
  }

  void Player::handleInput(InputHandler* input)
  {
    //TODO: handle key input
    /*
    if (input->getKey(SDL_SCANCODE_RIGHT))
      {
	if (_state == running || _state == standing) _xVelocity += _speed;
	else if (_state == jumping && _xVelocity > 0) _xVelocity = _speed;
	else if (_state == jumping && _xVelocity < 0)
	  {
	    _xVelocity = _airspeed;
	    // jumpDir = UP;
	  }
	else if (_state == jumping && _xVelocity == 0) _xVelocity = _airspeed;
      }
    if (input->getKey(SDL_SCANCODE_LEFT))
      {
	if (_state == running || _state == standing) _xVelocity -= _speed;
	else if (_state == jumping && _xVelocity > 0)
	  {
	    _xVelocity = -_airspeed;
	    // jumpDir = UP;
	  }
	else if (_state == jumping && _xVelocity < 0) _xVelocity = -_speed;
	else if (_state == jumping && _xVelocity == 0) _xVelocity = -_airspeed;
      }
    if (input->getPressed(SDL_SCANCODE_UP) || input->getPressed(SDL_SCANCODE_SPACE))
      {
	if(_state != jumping)
	  {
	    _yVelocity = 10; ///bra konstant
	    _state = jumping;
	  }	
      }*/
  }

  void Player::updateLogic(int difficulty)
  {
    //TODO: update logic
  }




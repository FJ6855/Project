#include "Player.h";

  void damage(float dmg)
  {
    _health-=dmg;
    //if(_health<=0)
      //_state = dead;
  }

  void affectSpeed(float speedFactor)
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

  bool isDead()//kan sättas ihop med den under med "dead" state?
  {
    return _state==dead;
  }
  
  playerState getState()
  {
    return _state;
  }

  int getScore()
  {
    return _score;
  }

  handleInput(inputHandler input)
  {
    //TODO: handle key input
    if (input->getKey(SDL_SCANCODE_RIGHT))
      {
	if (_state == running || _state == standing) _xVelocity += _speed;
	else if (_state == jumping && _xVelocity > 0) _xVelocity = _speed;
	else if (_state == jumping && _xVelocity < 0)
	  {
	    _xVelocity = _airSpeed;
	    // jumpDir = UP;
	  }
	else if (_state == jumping && _xVelocity == 0) _xVelocity = _airSpeed;
      }
    if (input->getKey(SDL_SCANCODE_LEFT))
      {
	if (_state == running || _state == standing) xVel -= speed;
	else if (_state == jumping && _xVelocity > 0)
	  {
	    _xVelocity = -_airSpeed;
	    // jumpDir = UP;
	  }
	else if (_state == jumping && _xVelocity < 0) _xVelocity = -_speed;
	else if (_state == jumping && _xVelocity == 0) _xVelocity = -_airSpeed;
      }
    if (input->getKeyPressed(SDL_SCANCODE_UP) || input->getKeyPressed(SDL_SCANCODE_SPACE))
      {
	if(_state != jumping)
	  {
	    _yVelocity = 10; /*bra konstant*/
	    _state = jumping;
	  }	
      }
  }

  updateLogic(int difficulty)
  {
    //TODO: update logic
  }




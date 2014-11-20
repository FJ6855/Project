#include "Object.h"
#include "InputHandler.h"

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerState {
	dead, 
	standing, 
	running, 
	jumping
};

class Player : public Object
{
 public:
 Player(int x, int y, int width, int height) 
   : Object(x, y, width, height)
    {
      _speed = 8;
      _gravity = 5;
      _xVel = 0;
      _yVel = 0;
      _playerState = jumping;
    }

  void handleInput(InputHandler* inputHandler);
  void updateLogic();

  float getXvel();
  float getYvel();
  int getSpeed();

  void setXvel(int xVel);;
  void setYvel(int yVel);

  void setState(PlayerState state);
  PlayerState getState();

 private:
  float _speed;
  float _gravity;
  float _xVel;
  float _yVel;

  PlayerState _playerState;
  /*
  float _airspeed;
  int _horizontalMovement;
  int _verticalMovement;
  int _score;
  float _health;
  playerState _state;
  */
};

#endif

#include "Object.h"
#include "InputHandler.h"

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerState {
	dead,
	running, 
	inAir
};

enum PlayerDirection {
	right,
	left
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
      _playerState = inAir;
       _playerDirection = right;
       _health = 100;
       _score = 0;
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

  void setState(PlayerDirection direction);
  PlayerDirection getDirection();

  int getHealth();
  void setHealth(int health);
  int getScore();
  void setScore(int score);

 private:
  float _speed;
  float _gravity;
  float _xVel;
  float _yVel;
  int _health;
  int _score;
  
  PlayerDirection _playerDirection;
  PlayerState _playerState;
};

#endif

#include "Object.h"
#include "InputHandler.h"

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerState {
	dead,
	running,
	jumping,
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
      _gravity = 0.45;
      _xVel = 0;
      _yVel = 0;
      _playerState = inAir;
      _playerDirection = right;
      _health = 100;
      _score = 0;
	  _healthLossFactor = 0.1f;
	  _jumpBoost = true;
	  _jumpBoostGravity = _gravity;

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

  float getHealth();
  void setHealth(int health);
  int getScore();
  void setScore(int score);

  void setDifficulty(int difficulty);

 private:
  float _speed;
  float _gravity;
  float _xVel;
  float _yVel;
  float _health;
  int _score;
  int _currentDifficulty;
  float _healthLossFactor;

  //jump control
  bool _jumpBoost;
  float _jumpBoostGravity;
  
  PlayerDirection _playerDirection;
  PlayerState _playerState;
};

#endif

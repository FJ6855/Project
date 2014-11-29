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
      _defaultSpeed = _speed;
      _gravity = 0.45f;
      _xVel = 0;
      _yVel = 0;
      _playerState = inAir;
      _playerDirection = right;
      _health = 100;
      _score = 0;
      _highscore = 0;
      _scoreOffset = 0;
      _healthLossFactor = 0.05f;
      _jumpBoost = true;
      _jumpBoostGravity = _gravity;
      
      _godMode = false;
    }

  void handleInput(InputHandler* inputHandler);
  void updateLogic();

  float getXvel();
  float getYvel();
  float getSpeed();
  void setSpeed(float speed);
  void resetSpeed();

  void setXvel(int xVel);
  void setYvel(int yVel);

  void setState(PlayerState state);
  PlayerState getState();

  void setState(PlayerDirection direction);
  PlayerDirection getDirection();

  float getHealth();
  void setHealth(int health);
  int getScore();
  void setScore(int score);
  void setHighscore(int highscore);
  int getHighscore();

  void setDifficulty(int difficulty);

 private:
  float _speed;
  float _defaultSpeed;
  float _gravity;
  float _xVel;
  float _yVel;
  float _health;
  int _score;
  int _highscore;
  float _scoreOffset;
  int _currentDifficulty;
  float _healthLossFactor;

  // testing
  bool _godMode;

  //jump control
  bool _jumpBoost;
  float _jumpBoostGravity;
  
  PlayerDirection _playerDirection;
  PlayerState _playerState;
};

#endif

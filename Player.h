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
      _airSpeed = 0;
      _gravity = 0.45f;
      _xVel = 0;
      _yVel = 0;
      _playerState = inAir;
      _playerDirection = right;
      _health = 100;
      _powerUpTimer = 0;
      _score = 0;
      _highscore = 0;
      _scoreOffset = 0;
      _healthLossFactor = 0.05f;
      _jumpBoost = true;
      _jumpBoostGravity = _gravity;
      _lastScore = 0;
      _movementDifference = 0;   
      _godMode = false;
      _lastX = _x;
    }

  void reset();

  void handleInput(InputHandler* inputHandler);
  void updateLogic();

  float getXvel();
  float getYvel();

  float getSpeed();
  void setSpeed(float speed);
  void resetSpeed();

  void setAirSpeed(float airSpeed);

  void setXvel(int xVel);
  void setYvel(int yVel);

  int getMovementDifference();
  void setMovementDifference(int movementDifference);

  void setState(PlayerState state);
  PlayerState getState();

  void setDirection(PlayerDirection direction);
  PlayerDirection getDirection();

  float getHealth();
  void setHealth(int health);
  
  int getPowerUpTimer();
  void setPowerUpTimer(int timer);

  int getScore();
  void setScore(int score);
  void setHighscore(int highscore);
  int getHighscore();

  void setLastScore(int lastScore);
  int getLastScore();

  void setDifficulty(int difficulty);

 private:
  float _speed;
  float _airSpeed;
  float _defaultSpeed;
  float _gravity;
  float _xVel;
  float _yVel;

  int _lastX;
  int _movementDifference;

  float _health;

  int _powerUpTimer;

  int _score;
  int _highscore;
  int _lastScore;
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

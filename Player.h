#include "Object.h"
#include "InputHandler.h"

#ifndef PLAYER_H
#define PLAYER_H

enum playerState {
	dead, 
	standing, 
	running, 
	jumping
};

class Player : public Object
{
 public:
 Player(int x, int y, int width, int height) 
   : _state{standing}, _health{100.0}, _speed{5.0}, _airspeed{0}, _gravity{5.0}
  , _horizontalMovement{0} , _verticalMovement{0}, _xVelocity{0}, _yVelocity{0}, _score{0}, Object(x, y, width, height){}

  void handleInput(InputHandler* inputHandler);
  void updateLogic();
  void updateLogic(int);

  void damage(float);
  void affectSpeed(float);
  bool isDead();

  playerState getState();
  int getScore();

 private:
  float _speed;
  float _airspeed;
  float _gravity;
  int _horizontalMovement;
  int _verticalMovement;
  int _xVelocity;
  int _yVelocity;
  int _score;
  float _health;
  playerState _state;
};

#endif

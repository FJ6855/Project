#include "Object.h"
#include "InputHandler.h"

#ifndef PLAYER_H
#define PLAYER_H

enum playerState{dead, standing, running, jumping};

class Player : public Object
{
 public:
 Player(int height, int width, int x, int y) 
   : _state{standing}, _health{100.0}, _speed{5.0/*bra konstant*/}, _airspeed{0}, _gravity{5.0/*bra konstant*/}
  , _horizontalMovement{0} , _verticalMovement{0}, _xVelocity{0}, _yVelocity{0}, _score{0}, Object(height,width,x,y){}

  void damage(float);
  void affectSpeed(float);
  bool isDead();//kan sättas ihop med den under med ett "dead" state?
  playerState getState();
  int getScore();
  void handleInput(InputHandler* inputHandler);
  void updateLogic();
  void updateLogic(int);

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

#include "Object.cc";

enum playerState{dead, standing, running, jumping};

Player : public Object
{
 public:
 Player(int height, int width, int x, int y): Object(height,width,x,y){}

  void damage(float);
  void affectSpeed(float);
  bool isDead();//kan sättas ihop med den under med ett "dead" state?
  playerState getState();
  int getScore();

  handleInput(inputHandler input);
  updateLogic(int difficulty);

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
}

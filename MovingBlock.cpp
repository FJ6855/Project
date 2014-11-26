#include "MovingBlock.h"
#include <iostream>

int MovingBlock::getMovingX()
{
  return _movingX;
}

void MovingBlock::updateLogic()
{
  _updates++;

  if(SDL_GetTicks() - _time >= 1000)
    {
      std::cout << "Updates per sec: " << _updates << std::endl;
      _updates = 0;
      _time = SDL_GetTicks();
    }

  if (_movingX >= _interval * _width || _movingX < 0)
    _speed = -_speed;
  //std::cout << "speed: " << _speed << std::endl;
  _movingX += _speed;
}

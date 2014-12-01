#include "MovingBlock.h"
#include <iostream>

int MovingBlock::getMovingX()
{
  return _movingX;
}

float MovingBlock::getSpeed()
{
  return _speed;
}

void MovingBlock::updateLogic()
{
  if (_movingX >= _interval * _width || _movingX < 0)
    _speed = -_speed;

  _movingX += _speed;
}

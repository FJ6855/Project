#include "MovingBlock.h"
#include <iostream>

int MovingBlock::getMovingX()
{
  return _movingX;
}

void MovingBlock::updateLogic()
{
  if (_movingX >= _interval * _width || _movingX < 0)
    _speed = -_speed;

  _movingX += _speed;
}

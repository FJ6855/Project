#include "MovingBlock.h"

MovingBlock* MovingBlock::clone() const
{
    return new MovingBlock(*this);
}

void MovingBlock::updateLogic()
{
    if (_movingX >= _interval * _width || _movingX < 0)
	_speed = -_speed;

    _movingX += _speed;
}

int MovingBlock::getMovingX()
{
    return _movingX;
}

float MovingBlock::getSpeed()
{
    return _speed;
}

#include "SpeedBlock.h"

SpeedBlock* SpeedBlock::clone() const
{
    return new SpeedBlock(*this);
}

int SpeedBlock::getSpeedFactor()
{
    return _speedFactor;
}

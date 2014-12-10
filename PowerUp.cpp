#include "PowerUp.h"

float PowerUp::getTimer()
{
    return _timer;
}

void PowerUp::setTimer(float timer)
{
    _timer = timer;
}

void PowerUp::updateLogic()
{
    _timer -= 16;
}

bool PowerUp::isActive()
{
    return _timer > 0;
}

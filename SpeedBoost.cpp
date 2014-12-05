#include "SpeedBoost.h"
#include <iostream>
#include "Player.h"

int SpeedBoost::getSpeed()
{
  return _speed;
}

void SpeedBoost::updateLogic()
{

}

void SpeedBoost::updateLogic(Player* player)
{
  if (PowerUp::isActive())
  {
      PowerUp::updateLogic();

      player->setSpeed(_speed);
  }
  else
  {
      player->resetSpeed();
  }
}

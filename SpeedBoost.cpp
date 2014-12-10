#include "SpeedBoost.h"
#include "Player.h"

void SpeedBoost::updateLogic()
{

}

void SpeedBoost::updateLogic(Player* player)
{
    PowerUp::updateLogic();

    if (PowerUp::isActive())
    {
	player->setSpeed(_speed);
    }
    else
    {
	player->resetSpeed();
    }
}

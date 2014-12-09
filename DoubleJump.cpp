#include "DoubleJump.h"
#include "Player.h"

void DoubleJump::updateLogic()
{

}

void DoubleJump::updateLogic(Player* player)
{
    PowerUp::updateLogic();

    if (PowerUp::isActive())
    {
	if (player->getState() == PlayerState::standing || player->getState() == PlayerState::running)
	{
	    player->setCanDoubleJump(true);
	}
    }
    else
    {
	player->setCanDoubleJump(false);
    }
}

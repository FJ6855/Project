#include "DoubleJump.h"
#include "Player.h"

DoubleJump* DoubleJump::clone() const
{
    return new DoubleJump(*this);
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

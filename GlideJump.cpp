#include "GlideJump.h"
#include "Player.h"

void GlideJump::updateLogic()
{

}

void GlideJump::updateLogic(Player* player)
{
    PowerUp::updateLogic();

    if (PowerUp::isActive())
    {
	if (_glideTimer > 0)
	{
	    player->setCanGlideJump(true);

	    _glideTimer -= 16;
	}
	else
	{
	    player->setCanGlideJump(false);
	}

	if (player->getState() == PlayerState::standing || player->getState() == PlayerState::running)
	{
	    _glideTimer = 1000;
	}
    }
    else
    {
	player->setCanGlideJump(false);
    }
}

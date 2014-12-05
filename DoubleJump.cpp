#include "DoubleJump.h"
#include "Player.h"
#include <iostream>
void DoubleJump::updateLogic()
{

}

void DoubleJump::updateLogic(Player* player)
{
    //PowerUp::updateLogic();

    if (PowerUp::isActive())
    {
	//std::cout << player->getState() << std::endl;
	//std::cout << player->getLastState() << std::endl;
	if (player->getState() == PlayerState::jumping && player->getLastState() == PlayerState::jumping)
	{
	    //std::cout << "double jump" << std::endl;
	    //player->resetJump();
	    player->setState(PlayerState::standing);
	}
	else
	{
	    //std::cout << "no double jump" << std::endl;
	}
    }
}

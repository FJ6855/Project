#include "PlayerRenderer.h"


#include <iostream>

PlayerRenderer::~PlayerRenderer()
{

}

void PlayerRenderer::loadContent()
{
  _playerTexture = _rm->loadTexture("playerTexture"); 
}

void PlayerRenderer::render(Player* player, SDL_Renderer* renderer)
{
  _playerTexture->render(renderer, 448 - (player->getWidth()/2), player->getY(), player->getWidth(), player->getHeight());
}


#include "ItemRenderer.h"

void ItemRenderer::loadContent() 
{
  _textures.push_back(_rm->loadTexture("health"));
  _textures.push_back(_rm->loadTexture("speedBoost"));
}

void ItemRenderer::render(Item* item, int offset, SDL_Renderer* renderer)
{
  _textures.at(item->getType())->render(renderer, item->getX() * item->getWidth() + offset, item->getY() * item->getHeight(), item->getWidth(), item->getHeight()); 
}

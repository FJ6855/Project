#include "ItemRenderer.h"

void ItemRenderer::loadContent() 
{
  _textures.push_back(_rm->loadTexture("item"));
}


void ItemRenderer::render(Item* item, int offset, SDL_Renderer* renderer)
{
  _textures.at(0)->render(renderer, item->getX() * item->getWidth() + offset, item->getY() * item->getHeight(), item->getWidth(), item->getHeight()); 
}

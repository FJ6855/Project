#include "BlockRenderer.h"

void BlockRenderer::loadContent() 
{
  _textures.push_back(_rm->loadTexture("block"));
}


void BlockRenderer::render(Block* block, SDL_Renderer* renderer)
{
  _textures.at(0)->render(renderer, block->getX() * block->getWidth(), block->getY() * block->getHeight(), block->getWidth(), block->getHeight()); 
}

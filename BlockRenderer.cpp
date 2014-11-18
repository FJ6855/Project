#include "BlockRenderer.h"

void BlockRenderer::loadContent() 
{
  _textures.push_back(_rm->loadTexture("block"));
}


void BlockRenderer::render(Block* block, int offset, SDL_Renderer* renderer)
{
  _textures.at(0)->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight()); 
}

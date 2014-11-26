#include "BlockRenderer.h"
#include "BlinkingBlock.h"

void BlockRenderer::loadContent() 
{
  _textures.push_back(_rm->loadTexture("block"));
  // TODO: add textures for BlinkingBlock and SpeedBlock
  _textures.push_back(_rm->loadTexture("block"));
  _textures.push_back(_rm->loadTexture("block"));
}


void BlockRenderer::render(Block* block, int offset, SDL_Renderer* renderer)
{
  BlinkingBlock* blinkingBlock = dynamic_cast<BlinkingBlock*>(block);
      
  if (blinkingBlock != nullptr)
    {
      if (blinkingBlock->isVisible())
	{
	  // TODO: Render blinking texture
	  _textures.at(0)->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
	}
      else
	{
	  // TODO: Render blinking texture
	  //_textures.at(0)->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
	}
    }
  else
    {
      _textures.at(block->getType())->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
    }
}

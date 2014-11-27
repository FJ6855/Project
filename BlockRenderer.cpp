#include "BlockRenderer.h"
#include "BlinkingBlock.h"
#include "MovingBlock.h"

void BlockRenderer::loadContent() 
{
  _textures.push_back(_rm->loadTexture("block"));
  _textures.push_back(_rm->loadTexture("blinkingBlockVisible"));  
  _textures.push_back(_rm->loadTexture("blinkingBlockInvisible"));
  _textures.push_back(_rm->loadTexture("speedBlock"));
}


void BlockRenderer::render(Block* block, int offset, SDL_Renderer* renderer)
{
  BlinkingBlock* blinkingBlock = dynamic_cast<BlinkingBlock*>(block);
  MovingBlock* movingBlock = dynamic_cast<MovingBlock*>(block);
      
  if (blinkingBlock != nullptr)
    {
      if (blinkingBlock->isVisible())
	{
	  _textures.at(1)->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
	}
      else
	{
	  _textures.at(2)->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
	}
    }
  else if (movingBlock != nullptr)
    {
      _textures.at(movingBlock->getType())->render(renderer, movingBlock->getX() * movingBlock->getWidth() + movingBlock->getMovingX() + offset, movingBlock->getY() * movingBlock->getHeight(), movingBlock->getWidth(), movingBlock->getHeight());
    }    
  else
    {
	_textures.at(block->getType())->render(renderer, block->getX() * block->getWidth() + offset, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
    }
}

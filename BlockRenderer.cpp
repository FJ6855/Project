#include "BlockRenderer.h"
#include "BlinkingBlock.h"
#include "MovingBlock.h"

void BlockRenderer::loadContent() 
{
    _textures.push_back(_rm->loadTexture("block"));
    _textures.push_back(_rm->loadTexture("blinkingBlockVisible"));  
    _textures.push_back(_rm->loadTexture("blinkingBlockInvisible"));
    _textures.push_back(_rm->loadTexture("speedBlockRight"));
    _textures.push_back(_rm->loadTexture("speedBlockLeft"));
}


void BlockRenderer::render(Block* block, int offset, SDL_Renderer* renderer)
{
    MovingBlock* movingBlock = dynamic_cast<MovingBlock*>(block);
      
    int x = block->getX() * block->getWidth() + offset;
    

    if (movingBlock != nullptr)
    {
	x += movingBlock->getMovingX();
    }

    _textures.at(block->getType())->render(renderer, x, block->getY() * block->getHeight(), block->getWidth(), block->getHeight());
}

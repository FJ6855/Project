#include "Renderer.h"
#include "ResourceManager.h"
#include "Block.h"

#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

class BlockRenderer : public Renderer
{
 public:
 BlockRenderer(ResourceManager* rm) : Renderer{rm} 
  {
    loadContent();
  }

  ~BlockRenderer() {}
  
  void loadContent() override;
  void render(Block* block, int offset, SDL_Renderer* renderer);

 private:
};

#endif


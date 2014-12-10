#include "Renderer.h"
#include "ResourceManager.h"
#include "Item.h"

#ifndef ITEM_RENDERER_H
#define ITEM_RENDERER_H

class ItemRenderer : public Renderer
{
public:
    ItemRenderer(ResourceManager* rm) : Renderer(rm) 
    {
	loadContent();
    }

    ~ItemRenderer() = default;
  
    void loadContent() override;
    void render(Item* item, int offset, SDL_Renderer* renderer);
};

#endif

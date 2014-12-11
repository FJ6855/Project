#include <vector>
#include "ResourceManager.h"

#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
public:
    Renderer(ResourceManager* rm) : _rm{rm} {}

    ~Renderer()
    {
	for(Texture* texture : _textures)
	{
	    delete texture;
	    texture = nullptr;
	}
    }

    virtual void loadContent() = 0;

protected:
    std::vector<Texture*> _textures;
    ResourceManager* _rm;
};

#endif

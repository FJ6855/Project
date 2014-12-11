#include <vector>
#include "ResourceManager.h"

#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
public:
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
    Renderer(ResourceManager* rm) : _rm{rm} {}
    Renderer(const Renderer&) = default;

    std::vector<Texture*> _textures;
    ResourceManager* _rm;
};

#endif

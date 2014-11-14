#include "Renderer.h"

Renderer::~Renderer()
{
  for(Texture* texture : _textures)
    delete texture;

  delete _rm;
}

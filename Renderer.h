#include <vector>
#include "ResourceManager.h"

#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
 public:
 Renderer(ResourceManager* rm) : _rm{rm} {}
  ~Renderer();

  virtual void loadContent() = 0;
 protected:
	std::vector<Texture*> _textures;
	ResourceManager* _rm;
 private:

};

#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "Texture.h"

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

class ResourceManager
{
 public:
	 ResourceManager(SDL_Renderer* renderer, TTF_Font* font) : _renderer{ renderer }, _font{ font } {}
	 ~ResourceManager();

	 Texture* loadTexture(std::string fileName);
	 Texture* loadTexture(int width, int height, int red, int green, int blue);
	 Texture* loadTexture(std::string textureText, SDL_Color textColor);
 protected:

 private:
	 SDL_Renderer* _renderer;
	 TTF_Font* _font;
};

#endif
